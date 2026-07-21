import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int d = sc.nextInt();
		int g = sc.nextInt() / 100;
		int[] p = new int[d];
		int[] c = new int[d];
		for (int i = 0; i < d; i++) {
			p[i] = sc.nextInt();
			c[i] = sc.nextInt() / 100;
		}
		sc.close();

		int ans = 1000;
		int end = 1 << d;
		label:
		for (int i = 0; i < end; i++) {
			int val = 0;
			int sum = 0;
			for (int j = 0; j < d; j++) {
				if ((i >> j & 1) == 1) {
					val += p[j];
					sum += p[j] * (j + 1) + c[j];
				}
			}
			if (sum >= g) {
				ans = Math.min(ans, val);
				continue;
			}
			for (int j = d - 1; j >= 0; j--) {
				if ((i >> j & 1) == 0) {
					int v = (p[j] - 1) * (j + 1);
					if (sum + v < g) {
						sum += v;
						val += p[j] - 1;
					} else {
						int rem = g - sum;
						int x = (rem + j) / (j + 1);
						val += x;
						ans = Math.min(ans, val);
						continue label;
					}
				}
			}
		}
		System.out.println(ans);
	}
}
