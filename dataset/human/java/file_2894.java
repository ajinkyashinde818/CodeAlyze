import static java.lang.Math.abs;
import static java.lang.Math.atan2;
import static java.lang.Math.sqrt;
import static java.util.Arrays.deepToString;

import java.util.Arrays;
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
		
		int[] ms = {
			1, 2, 1, 2, 1, 4, 1, 4,
			1, 2, 1, 2, 1, 4, 1, 4,
		};

		for (;sc.hasNext();) {
			int[] a = new int[8];
			for (int i = 0; i < 8; i++) a[i] = sc.nextInt();
			
			int best = -1;
			int best_pos = 0;
			for (int p = 0; p < 8; p++) {
				int here = 0;
				for (int i = 0; i < 8; i++) {
					int r = Math.min(a[i], ms[i + p]);
					here += r;
				}
				if (best < here) {
					best = here;
					best_pos = p;
				} else if (best == here && lt(p, best_pos, ms)) {
					best = here;
					best_pos = p;
				}
			}
			
			System.out.print(ms[best_pos]);
			for (int i = 1; i < 8; i++) {
				System.out.print(" " + ms[i+best_pos]);
			}
			System.out.println();
		}
	}
	boolean lt(int p, int best_pos, int[] ms) {
		for (int i = 0; i < 8; i++) {
			if (ms[i + p] < ms[i + best_pos]) return true;
			if (ms[i + p] > ms[i + best_pos]) return false;
		}
		return false;
	}
}
