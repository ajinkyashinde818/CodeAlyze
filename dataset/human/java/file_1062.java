import java.util.Scanner;

public class Main {
	public static boolean isIn(double r, double wx, double wy, double x, double y) {
		double len = Math.hypot(wx - x, wy - y);
		return len <= r ? true : false;
	}

	public static boolean isVisible(double r, double wx, double wy, double tx, double ty, double sx, double sy) {
		double a1, b1, a2, b2;
		double xx, yy;

		if (tx == sx) {
			a1 = Double.POSITIVE_INFINITY;
			b1 = Double.NaN;
		} else {
			a1 = (ty - sy) / (tx - sx);
			b1 = ty - a1 * tx;
		}

		if (a1 == Double.POSITIVE_INFINITY) {
			xx = tx;
			yy = wy;
		} else if (a1 == 0) {
			xx = wx;
			yy = ty;
		} else {
			a2 = -1.0 / a1;
			b2 = wy - a2 * wx;

			yy = (a2 * b1 - a1 * b2) / (a2 - a1);
			xx = (yy - b1) / a1;
		}

		if ((tx * sy - sx * ty) != 0) {
			if (0 < (tx * yy - xx * ty) * (sx * yy - xx * sy)) {
				return true;
			}
		} else {
			double ntx = tx - 1;
			double nty = ty;
			double nsx = sx - 1;
			double nsy = sy;
			double nxx = xx - 1;
			double nyy = yy;
			if (0 < (ntx * nyy - nxx * nty) * (nsx * nyy - nxx * nsy)) {
				return true;
			}
		}

		return !isIn(r, wx, wy, xx, yy);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, m;
		double wx[], wy[], r[];
		double tx, ty;
		double sx, sy;
		boolean flag;

		while (true) {
			n = sc.nextInt();
			if (n == 0) {
				break;
			}
			wx = new double[n];
			wy = new double[n];
			r = new double[n];
			for (int i = 0; i < n; i++) {
				wx[i] = sc.nextInt();
				wy[i] = sc.nextInt();
				r[i] = sc.nextInt();
			}
			m = sc.nextInt();
			while (m-- != 0) {
				tx = sc.nextInt();
				ty = sc.nextInt();
				sx = sc.nextInt();
				sy = sc.nextInt();
				flag = true;
				for (int i = 0; i < n; i++) {
					if (isIn(r[i], wx[i], wy[i], tx, ty) != isIn(r[i], wx[i], wy[i], sx, sy)) {
						flag = false;
					} else if (!isIn(r[i], wx[i], wy[i], tx, ty)) {
						if (!isVisible(r[i], wx[i], wy[i], tx, ty, sx, sy)) {
							flag = false;
						}
					}
				}
				System.out.println(!flag ? "Safe" : "Danger");
			}
		}
	}
}
