// practice with kaiboy
import java.io.*;
import java.util.*;

public class Main extends PrintWriter {
	Main() { super(System.out, true); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		Main o = new Main(); o.main(); o.flush();
	}

	static final double INF = 4e9;
	void main() {
		int xs = sc.nextInt();
		int ys = sc.nextInt();
		int xt = sc.nextInt();
		int yt = sc.nextInt();
		int n = sc.nextInt();
		int[] xx = new int[n + 2];
		int[] yy = new int[n + 2];
		int[] rr = new int[n + 2];
		xx[0] = xs; yy[0] = ys;
		xx[n + 1] = xt; yy[n + 1] = yt;
		for (int i = 1; i <= n; i++) {
			xx[i] = sc.nextInt();
			yy[i] = sc.nextInt();
			rr[i] = sc.nextInt();
		}
		n += 2;
		double[] dd = new double[n]; Arrays.fill(dd, INF); dd[0] = 0;
		boolean[] used = new boolean[n];
		while (true) {
			int i = -1;
			for (int j = 0; j < n; j++)
				if (!used[j]) {
					if (i == -1 || dd[i] > dd[j])
						i = j;
				}
			if (i == -1)
				break;
			used[i] = true;
			for (int j = 0; j < n; j++)
				if (!used[j])
					dd[j] = Math.min(dd[j], dd[i] + Math.max(Math.hypot(xx[i] - xx[j], yy[i] - yy[j]) - rr[i] - rr[j], 0));
		}
		println(dd[n - 1]);
	}
}
