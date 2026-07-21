import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();
		int[] c = new int[n];
		int[] a = new int[n * m];
		int[] aSum = new int[m];
		for (int i = 0; i < n; ++i) {
			c[i] = sc.nextInt();
			for (int j = 0; j < m; ++j) {
				a[m * i + j] = sc.nextInt();
				aSum[j] += a[m * i + j];
			}
		}

		for (int i = 0; i < m; ++i) {
			if (aSum[i] < x) {
				System.out.println(-1);
				return;
			}
		}

		int ans = 1 << 30;
		int[] richard = new int[m];
		for (int num = 0; num < (1 << n); ++num) {
			String bin = getBinary(num, n);
			Arrays.fill(richard, 0);
			int cost = 0;
			for (int i = 0; i < n; ++i) {
				char bit = bin.charAt(i);
				if (bit == '1') {
					cost += c[i];
					for (int j = 0; j < m; ++j) {
						richard[j] += a[m * i + j];
					}
				}
			}

			if (hasSmaller(richard, x)) {
				continue;
			}

			ans = Math.min(ans, cost);
		}

		System.out.println(ans);
	}

	private static boolean hasSmaller(int[] richard, int x) {
		// TODO 自動生成されたメソッド・スタブ
		for (int i = 0; i < richard.length; ++i) {
			if (richard[i] < x) {
				return true;
			}
		}
		return false;
	}

	private static String getBinary(int num, int n) {
		// TODO 自動生成されたメソッド・スタブ
		StringBuilder sb = new StringBuilder();
		for (int cnt = 0; cnt < n; ++cnt) {
			sb.append(num % 2);
			num /= 2;
		}
		return sb.toString();
	}

}
