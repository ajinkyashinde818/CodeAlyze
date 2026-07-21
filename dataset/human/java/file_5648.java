import java.util.*;
import java.util.stream.Collectors;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class Main {
	int N, K;
	long S;
	List<Long> result;

	public static void main(String[] args) throws IOException {
		InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
		BufferedReader in = new BufferedReader(reader);
		Main ins = new Main(in);
		ins.calc();
		ins.showResult();
	}

	Main(BufferedReader in) throws IOException {
		String[] tokens = in.readLine().split(" ");
		this.N = Integer.parseInt(tokens[0]);
		this.K = Integer.parseInt(tokens[1]);
		this.S = Long.parseLong(tokens[2]);

	}

	void calc() {
		this.result = new ArrayList<>(N);
		for (int i = 0; i < K; ++i) {
			result.add(S);
		}
		// 残りの値が重要
		long remain = 1L;
		if (N - K > 0) {
			remain = (S - 1) / (N - K);
			if (remain == 0) {
				remain = 1000000000L;
			}
		}
		for (int i = K; i < N; ++i) {
			result.add(remain);
		}
	}

	void showResult() {
		StringBuilder strBuilder = new StringBuilder();
		strBuilder.append(Long.toString(result.get(0)));
		for (int i = 1; i < N; ++i) {
			strBuilder.append(" " + Long.toString(result.get(i)));
		}
		System.out.println(strBuilder.toString());
	}
}
