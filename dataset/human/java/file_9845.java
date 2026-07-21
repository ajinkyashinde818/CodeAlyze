import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();
		int c[] = new int[n];
		int a[][] = new int[n][m];

		for (int i = 0; i < n; i++) {
			c[i] = sc.nextInt();
			for (int j = 0; j < m; j++) {
				a[i][j] = sc.nextInt();
			}
		}

		int min = Integer.MAX_VALUE;
		for (int i = 0; i < (1 << n); i++) {
			int value = 0;
			int aNow[] = new int[m];
			boolean can = true;
			for (int j = 0; j < n; j++) {
				if ((i >> j & 1) == 1) {
					value += c[j];
					for (int k = 0; k < m; k++) {
						aNow[k] += a[j][k];
					}
				}
			}
			for (int k = 0; k < m; k++) {
				if (aNow[k] < x) can = false;
			}
			if (can) min = Math.min(min, value);
		}

		if (min == Integer.MAX_VALUE) {
			System.out.println(-1);
		} else {
			System.out.println(min);
		}



		sc.close();

	}

}
