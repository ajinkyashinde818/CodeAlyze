import java.io.*;
import java.util.*;


public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		int d = sc.nextInt();
		long g = sc.nextLong();

		int[] p = new int[d];
		int[] c = new int[d];
		int sum = 0;
		for (int i = 0; i < d; i++) {
			p[i] = sc.nextInt();
			c[i] = sc.nextInt();
			sum += p[i];
		}

		long[] dp = new long[sum + 1];
		Arrays.fill(dp, -1);
		dp[0] = 0;
		
		for (int i = 0; i < d; i++) {
			for (int j = sum; j >= 0; j--) {
				if (dp[j] < 0) {
					continue;
				}

				for (int k = 1; k <= p[i]; k++) {
					int score = 100 * (i + 1) * k;
					if (k == p[i]) {
						score += c[i];
					}
					dp[j + k] = Math.max(dp[j + k], dp[j] + score);
				}
			}
		}

		for (int i = 1; true; i++) {
			if (dp[i] >= g) {
				pr.println(i);
				break;
			}
		}
	}

	// ---------------------------------------------------
	public static void main(String[] args) {
		sc = new Scanner(INPUT == null ? System.in : new ByteArrayInputStream(INPUT.getBytes()));
		pr = new Printer(System.out);

		solve();

//		pr.close();
		pr.flush();
//		sc.close();
	}

	static String INPUT = null;

	private static class Printer extends PrintWriter {
		Printer(OutputStream out) {
			super(out);
		}
	}
}
