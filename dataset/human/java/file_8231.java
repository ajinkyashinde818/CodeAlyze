import java.util.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class Main {
	int A, B;
	long result;

	public static void main(String[] args) throws IOException {
		InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
		BufferedReader in = new BufferedReader(reader);
		Main ins = new Main(in);
		ins.calc();
		ins.showResult();
	}

	Main(BufferedReader in) throws IOException {
		String[] tokens = in.readLine().split(" ");
		A = Integer.parseInt(tokens[0]);
		B = Integer.parseInt(tokens[1]);
	}

	int gcd(int large, int small) {
		if (large < small) {
			return gcd(small, large);
		}
		if (large % small == 0) {
			return small;
		}
		return gcd(small, large % small);
	}

	void calc() {
		int gcd = gcd(A, B);
		result = (long) A * (long) B / (long) gcd;
	}

	void showResult() {
		System.out.println(result);
	}
}
