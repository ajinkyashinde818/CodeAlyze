import java.util.*;
import java.util.stream.Collectors;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class Main {
	String N;
	long result = 0;
	long[][] dp;

	public static void main(String[] args) throws IOException {
		InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
		BufferedReader in = new BufferedReader(reader);
		Main ins = new Main(in);
		ins.calc();
		ins.showResult();
	}

	void sub(int keta) {
		int val = Integer.parseInt(N.substring(keta, keta + 1));
		// ピッタリ払う場合; dp[keta-1][0] + ピッタリ払う or 前の状態で余分に払っている分のおつりをもらう
		dp[keta + 1][0] = Math.min(dp[keta][0] + val, dp[keta][1] + (10 - val));

		// 超える範囲で払う場合
		// ピッタリ払う + val+1払う
		// or
		// 超えている分 - 1少ないおつりもらう
		dp[keta + 1][1] = Math.min(dp[keta][0] + val + 1, dp[keta][1] + (10 - val - 1));
	}

	Main(BufferedReader in) throws IOException {
		N = in.readLine();
		// 0: ピッタリ払う，1: 超える最小値
		this.dp = new long[N.length() + 1][2];
		dp[0][0] = 0;
		dp[0][1] = 1;

	}

	void calc() {
		for (int i = 0; i < N.length(); ++i) {
			sub(i);
		}
		result = Math.min(dp[N.length()][0], dp[N.length()][1]+1);
	}

	void showResult() {
		System.out.println(result);
	}
}
