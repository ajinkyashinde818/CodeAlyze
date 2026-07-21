import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();
		int[] c = new int[n];
		long[][] a = new long[n][m];

		for (int i = 0; i < n; i++) {
			c[i] = Integer.parseInt(sc.next());
			for (int j = 0; j < m; j++) {
				a[i][j] = Long.parseLong(sc.next());
			}
		}

		long min = 1000000000;
		char[] sp = new char[n];

		for (int i = 1; i < Math.pow(2, n); i++) {

			sp = String.format("%0" + n + "d", Long.parseLong(Integer.toBinaryString(i))).toCharArray();
			long[] ac = new long[m];

			for (int j = 0; j < n; j++) {
				if (sp[j] == '0')
					continue;
				for (int k = 0; k < m; k++) {
					ac[k] += a[j][k];
				}
			}
			boolean flg = true;
			for (int j = 0; j < m; j++) {
				if (ac[j] < x)
					flg = false;
			}
			if (flg) {
				long ans = 0;
				for (int j = 0; j < n; j++) {
					if (sp[j] == '1')
						ans += c[j];
				}
				min = Math.min(min, ans);
			}
		}
		if (min == 1000000000)
			min = -1;

		System.out.println(min);

	}

}
