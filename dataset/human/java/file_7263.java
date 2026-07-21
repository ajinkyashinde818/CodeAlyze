import java.util.*;
import java.util.stream.Collectors;
import java.io.*;
import java.math.BigDecimal;
import java.nio.charset.StandardCharsets;

public class Main {
	int K, N;
	int[] A;

	public static void main(String[] args) throws IOException {
		InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
		BufferedReader in = new BufferedReader(reader);
		Main ins = new Main(in);
		ins.calc();
		ins.showResult();
	}

	Main(BufferedReader in) throws IOException {
		String[] tokens = in.readLine().split(" ");
		K = Integer.parseInt(tokens[0]);
		N = Integer.parseInt(tokens[1]);
		A = new int[N];
		tokens = in.readLine().split(" ");
		for (int i = 0; i < N; ++i) {
			A[i] = Integer.parseInt(tokens[i]);
		}

	}

	void calc() {
		int result = A[N - 1] - A[0];
		for (int i = 0; i + 1 < N; ++i) {
			result = Math.min(result, K - (A[i + 1] - A[i]));
		}
		System.out.println(result);
	}

	void showResult() {
	}

}
