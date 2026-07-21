import java.awt.Point;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	static int n;
	static int wayn;
	static int railn;
	static int[] ar;
	static int[] br;
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		ar = new int[n+1];
		br = new int[n+1];
		wayn = sc.nextInt();
		railn = sc.nextInt();
		for(int i = 0; i <= n; i++) {
			ar[i] = i;
			br[i] = i;
		}
		for(int i = 0; i < wayn; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			unite(a, b);
		}
		for(int i = 0; i < railn; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			bunite(a, b);
		}
		HashMap<Point, Integer> map = new HashMap<>();
		for(int i = 1; i <= n; i++) {
			Point p = new Point(root(i),broot(i));
			if(map.containsKey(p)) {
				map.put(p, map.get(p)+1);
			} else {
				map.put(p, 1);
			}
		}
		for(int i = 1; i <= n; i++) {
			System.out.println(map.get(new Point(root(i),broot(i))));
		}
	}
	static int root(int x) {
		if(ar[x]==x) {
			return x;
		} else {
			return ar[x] = root(ar[x]);
		}
	}
	static boolean same(int x, int y) {
		return root(x)==root(y);
	}
	static void unite(int x, int y) {
		x = root(x);
		y = root(y);
		if(x == y) return;
		ar[x] = y;
	}

	static int broot(int x) {
		if(br[x]==x) {
			return x;
		} else {
			return br[x] = broot(br[x]);
		}
	}
	static boolean bsame(int x, int y) {
		return broot(x)==broot(y);
	}
	static void bunite(int x, int y) {
		x = broot(x);
		y = broot(y);
		if(x == y) return;
		br[x] = y;
	}
}
