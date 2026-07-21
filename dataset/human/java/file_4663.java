import static java.util.Arrays.deepToString;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}
	void tr(Object... os) {
		System.err.println(deepToString(os));
	}

	Scanner sc = new Scanner(System.in);
	public void run() {
		for (;sc.hasNext();) {
			int m = sc.nextInt();
			int n = sc.nextInt();
			if (n == 0 && m == 0) break;
			int[] w = new int[n];
			for (int i = 0; i < n; i++) w[i] = sc.nextInt();
			int hi = 10000000;
			int lo = 1;
			while (hi - lo > 1) {
				int mid = (hi + lo) / 2;
				if (possible(mid, m, w)) hi = mid; else lo = mid;
			}
			System.out.println(hi);
		}
	}
	boolean possible(int W, int m, int[] w) {
		int need = 0;
		need++;
		int pos = 0;
		for (int i = 0; i < w.length; i++) {
			if (pos + w[i] > W) {
				need++;
				pos = w[i];
				if (w[i] > W) return false;
			} else {
				pos += w[i];
			}
		}
		return need <= m;
	}
}
