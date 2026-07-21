import java.util.Arrays;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int D = sc.nextInt();
		long G = sc.nextLong() / 100;
		long[] p = new long[D];
		long[] c = new long[D];
		for (int i = 0; i < D; ++i) {
			p[i] = sc.nextLong();
			c[i] = sc.nextLong() / 100;
		}
		long ans = Long.MAX_VALUE / 3;
		for (int s = 0; s < 1 << D; ++s) {
			long sum1 = 0, sum2 = 0;
			for (int i = 0; i < D; ++i) {
				if ((s & (1 << i)) > 0) {
					sum1 += p[i];
					sum2 += p[i] * (i + 1) + c[i];
				}
			}
			if (sum2 >= G)
				ans = Math.min(ans, sum1);
			for (int j = 0; j < D; ++j) {
				if ((s & (1 << j)) > 0)
					continue;
				long res = p[j];
				long tmp1 = sum1, tmp2 = sum2;
				while (tmp2 < G && res > 0) {
					++tmp1;
					tmp2 += (j + 1);
					--res;
				}
				if (res == 0)
					tmp2 += c[j];
				if (tmp2 >= G)
					ans = Math.min(ans, tmp1);
			}
		}
		System.out.println(ans);
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}
