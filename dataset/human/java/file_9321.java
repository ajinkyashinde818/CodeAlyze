import java.util.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class Main {

	public static void main(String[] args) throws IOException {
		InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
		BufferedReader in = new BufferedReader(reader);
		Main ins = new Main(in);
		ins.calc();
		ins.showResult();
	}

	int[][] D;

	Main(BufferedReader in) throws IOException {
		int N = Integer.parseInt(in.readLine());
		D = new int[N][2];
		for (int i = 0; i < N; ++i) {
			String[] tokens = in.readLine().split(" ");
			D[i][0] = Integer.parseInt(tokens[0]);
			D[i][1] = Integer.parseInt(tokens[1]);
		}

		boolean result = false;
		for (int i = 0; i + 2 < N; ++i) {
			if (check(i)) {
				result = true;
				break;
			}
		}
		if (result) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}

	boolean check(int i) {
		if (isSame(i) && isSame(i + 1) && isSame(i + 2)) {
			return true;
		} else {
			return false;
		}
	}

	boolean isSame(int i) {
		if (D[i][0] == D[i][1]) {
			return true;
		} else {
			return false;
		}
	}

	void calc() {
	}

	void showResult() {
	}
}
