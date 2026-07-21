import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int xs = sc.nextInt();
		int ys = sc.nextInt();
		int xt = sc.nextInt();
		int yt = sc.nextInt();
		int n = sc.nextInt();
		Obj[] arr = new Obj[n + 2];
		for (int i = 1; i <= n; i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			int r = sc.nextInt();
			Obj o = new Obj(i, x, y, r, 1e18);
			arr[i] = o;
		}
		sc.close();

		arr[0] = new Obj(0, xs, ys, 0, 0);
		arr[n + 1] = new Obj(n + 1, xt, yt, 0, 1e18);

		PriorityQueue<Obj> que = new PriorityQueue<>((o1, o2) -> Double.compare(o1.d, o2.d));
		que.add(arr[0]);
		double[] d = new double[n + 2];
		Arrays.fill(d, 1e18);
		d[0] = 0;
		while (!que.isEmpty()) {
			Obj cur = que.poll();
			if (cur.d != d[cur.i]) {
				continue;
			}
			for (int i = 1; i < n + 2; i++) {
				Obj next = arr[i];
				double dd = Math.hypot(cur.x - next.x, cur.y - next.y);
				double alt = cur.d + Math.max(dd - cur.r - next.r, 0);
				if (alt < d[i]) {
					que.add(new Obj(i, next.x, next.y, next.r, alt));
					d[i] = alt;
				}
			}
		}
		System.out.println(d[n + 1]);
	}

	static class Obj {
		int i, x, y, r;
		double d;

		public Obj(int i, int x, int y, int r, double d) {
			this.i = i;
			this.x = x;
			this.y = y;
			this.r = r;
			this.d = d;
		}
	}
}
