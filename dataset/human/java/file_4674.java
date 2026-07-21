import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static long[] dp3 = new long[100001];
	static long[] dp5 = new long[100001];
	static final int MOD = 100000007;

	public static void main(String[] args) throws Exception {
		calc(dp3, 3);
		calc(dp5, 5);
		while (true) {
			String line = sc.next();
			if (line.equals("#")) return;
			char cur = line.charAt(0);
			int count = 1;
			long ans = 1;
			for (int i = 1; i < line.length(); ++i) {
				if (line.charAt(i) != cur) {
					ans *= solve(count, cur - '0');
					ans %= MOD;
					cur = line.charAt(i);
					count = 1;
				} else {
					++count;
				}
			}
			ans *= solve(count, cur - '0');
			ans %= MOD;
			System.out.println(ans);
		}
	}

	static long solve(int len, int button) {
		long ret = 0;
		if (button == 0 || button == 8) {
			while(len > 0){
				ret += dp3[len];
				if(ret >= MOD) ret -= MOD;
				len -= 3;
			}
		} else {
			while(len > 0){
				ret += dp5[len];
				if(ret >= MOD) ret -= MOD;
				len -= 5;
			}
		}
		return ret;
	}

	static void calc(long[] dp, int base) {
		dp[0] = 1;
		for (int i = 1; i <= 100000; ++i) {
			for (int j = 1; j <= base && i - j >= 0; ++j) {
				dp[i] += dp[i - j];
				if (dp[i] >= MOD) dp[i] -= MOD;
			}
		}
	}

}
