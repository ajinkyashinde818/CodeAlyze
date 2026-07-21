import java.util.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class Main {
	long N;
	long result = 0;

	public static void main(String[] args) throws IOException {
		InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
		BufferedReader in = new BufferedReader(reader);
		Main ins = new Main(in);
		ins.calc();
		ins.showResult();
	}

	Main(BufferedReader in) throws IOException {
		N = Long.parseLong(in.readLine());
	}

	void calc() {
		if (N % 2 == 1) {
			// 0のまま
			return;
		}
		for(long div = 10; div <= N; div = div*5) {
			result += N/div;
		}
	}


	void showResult() {
		System.out.println(result);
	}
}
