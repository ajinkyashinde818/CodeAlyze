import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

	static final boolean debugMode = false;

	static final long DIV_INF = 1000000007l;

	static int n, m, x;
	static int[] c;
	static int[][] a;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = readInt(sc);
		m = readInt(sc);
		x = readInt(sc);

		c = new int[n];
		a = new int[n][m];

		for (int i = 0; i < n; i++) {
			c[i] = readInt(sc);
			for (int j = 0; j < m; j++) {
				a[i][j] = readInt(sc);
			}
		}

		int[] und = new int[m];// 理解度

		int res = dfs(0, 0, und);

		System.out.println(res == 99999999 ? -1 : res);

	}

	static int dfs(int depth, int cost, int[] und) {
		if (depth == n) {
			for (int u : und) {
				if (u < x) {
					return 99999999;
				}
			}
			return cost;
		}

		// depth番目の本を買う場合
		int[] und2 = Arrays.copyOf(und, und.length);
		for (int i = 0; i < m; i++) {
			und2[i] += a[depth][i];
		}

		return Math.min(dfs(depth + 1, cost, und), dfs(depth + 1, cost + c[depth], und2));

	}

	static int readInt(Scanner sc) {
		return Integer.parseInt(sc.next());
	}

	static Long readLong(Scanner sc) {
		return Long.parseLong(sc.next());
	}

	static void log(String s) {
		if (debugMode) {
			System.out.println(s);
		}
		return;
	}
}

class KrmlUtil {
	// a >= b
	static int gcd(int a, int b) {
		while (true) {
			if (b == 0)
				break;

			int mod = a % b;
			a = b;
			b = mod;
		}
		return a;
	}

	// a >= b
	static int lcm(int a, int b) {
		return a * b / gcd(a, b);
	}

	// a >= b
	static long gcd(long a, long b) {
		while (true) {
			if (b == 0)
				break;

			long mod = a % b;
			a = b;
			b = mod;
		}
		return a;
	}

	// a >= b
	static long lcm(long a, long b) {
		return a * b / gcd(a, b);
	}

	static BigInteger gcd(BigInteger a, BigInteger b) {
		return a.gcd(b);
	}

	static BigInteger lcm(BigInteger a, BigInteger b) {
		return a.divide(a.gcd(b)).multiply(b);
	}
}

class Pair {
	private int x;
	private int y;

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public Pair() {

	}

	public Pair(int x, int y) {
		this.x = x;
		this.y = y;
	}

}
