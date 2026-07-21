import java.util.*;

public class Main {
	static long MOD = (long) 1e9 + 7;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long dp[] = new long[n + 1];
		Arrays.fill(dp, -1);
		int m = sc.nextInt();
		final long MOD = 1_000_000_007l;
		int[] a = new int[m];
		for (int i = 0; i < m; i++) {
			a[i] = sc.nextInt();
			if (i >= 1 && a[i] - a[i - 1] == 1) {
				System.out.println(0);
				System.exit(0);
			}
			dp[a[i]] = 0;
		}
		sc.close();

		dp[0] = 1;
		for (int i = 1; i < n + 1; i++) {
			if (dp[i] == -1) {
				dp[i] = dp[i - 1] + (i >= 2 ? dp[i - 2] : 0);
				dp[i] %= MOD;
			}
		}
		System.out.println(dp[n]);
	}

	public static int arrayMax(int[] array) {
		int ans = Integer.MIN_VALUE;
		for (int i = 0; i < array.length; i++) {
			if (array[i] > ans)
				ans = array[i];
		}
		return ans;
	}

	public static int[] arrayInt(Scanner sc, int n) {
		int[] array = new int[n];
		for (int i = 0; i < n; i++) {
			array[i] = sc.nextInt();
		}
		return array;
	}

	public static Integer[] arrayInteger(Scanner sc, int n) {
		Integer[] array = new Integer[n];
		for (int i = 0; i < n; i++) {
			array[i] = sc.nextInt();
		}
		return array;
	}

	public static long[] arrayLong(Scanner sc, int n) {
		long[] array = new long[n];
		for (int i = 0; i < n; i++) {
			array[i] = sc.nextLong();
		}
		return array;
	}

	public static double[] arrayDouble(Scanner sc, int n) {
		double[] array = new double[n];
		for (int i = 0; i < n; i++) {
			array[i] = sc.nextDouble();
		}
		return array;
	}
}
