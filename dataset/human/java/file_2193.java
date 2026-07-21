import java.util.HashMap;
import java.util.Scanner;

public class Main {

	public static String Y = "Yes";
	public static String N = "No";
	public static long MOD = (long) (Math.pow(10, 9) + 7);
	public static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {

		long n = nl();
		long x = n;

		HashMap<Long, Integer> hs = new HashMap<>();

		String s = "";
		for (long i = 2; i <= Math.sqrt(n) + 1;) {
			if (x % i == 0) { // 最小の因数を求める
				s += i + " ";
				if (hs.get(i) == null) {
					hs.put(i, 1);
				} else {
					hs.put(i, hs.get(i) + 1);
				}
				x /= i; // 最小の因数で割った数を代入する
			} else
				i += 1;

			//			if (i > Math.ceil(Math.sqrt(n))) {
			//				s += x;
			//				if (hs.get(x) == null) {
			//					hs.put(x, 1);
			//				} else {
			//					hs.put(x, hs.get(x) + 1);
			//				}
			//			}
		}

		if (hs.get(x) == null) {
			hs.put(x, 1);
		} else {
			hs.put(x, hs.get(x) + 1);
		}

		int count = 0;
		int onecount = 0;

		if (hs.get(1l) == null) {
			onecount = 0;
		} else {
			onecount = hs.get(1l);
		}

		for (int a : hs.values()) {

			int sum = 0;
			for (int i = 1; i <= 100; i++) {
				sum += i;
				if (sum > a) {
					count += i - 1;

					break;
				} else if (sum == a) {
					count += i;
					break;
				}
			}
		}

		if (n == 1) {
			out(0);
		} else if (count == 1) {
			out(1);
		} else {
			if (onecount == 1) {
				out(count - 1);
			} else {
				out(count);
			}
		}
	}

	/*
	 * 以下メソッド集
	 */
	static int ni() {
		return sc.nextInt();
	}

	static long nl() {
		return sc.nextLong();
	}

	static double nd() {
		return sc.nextDouble();
	}

	static String n() {
		return sc.next();
	}

	static char[] nc() {
		return sc.next().toCharArray();
	}

	static int kaijo(int n) {
		if (n == 0 || n == 1) {
			return 1;
		} else {
			return n * kaijo(n - 1);
		}
	}

	static int fib(int n) {
		return (n == 1 || n == 0) ? n : fib(n - 2) + fib(n - 1);
	}

	static long lcm(long m, long n) {

		return m * n / gcd(m, n);
	}

	static int lcm(int m, int n) {

		return m * n / gcd(m, n);
	}

	static long gcd(long a, long b) {
		return (b == 0) ? a : gcd(b, a % b);
	}

	static int gcd(int a, int b) {
		return (b == 0) ? a : gcd(b, a % b);
	}

	static void out(String info) {
		System.out.println(info);
	}

	static void out(int info) {
		System.out.println(info);
	}

	static void out(double info) {
		System.out.println(info);
	}

	static void out(long info) {
		System.out.println(info);
	}

	static void out(char info) {
		System.out.println(info);
	}

	static void out(Object obj) {
		System.out.println(obj.toString());
	}

	static void outn(String info) {
		System.out.print(info);
	}

	static void outn(int info) {
		System.out.print(info);
	}

	static void outn(double info) {
		System.out.print(info);
	}

	static void outn(long info) {
		System.out.print(info);
	}

	static void outn(char info) {
		System.out.print(info);
	}

	static int max(int a, int b) {
		return Math.max(a, b);
	}

	static long max(long a, long b) {
		return Math.max(a, b);
	}

	static int min(int a, int b) {
		return Math.min(a, b);
	}

	static long min(long a, long b) {
		return Math.min(a, b);
	}
}

class XY {
	int h;
	int c;

	XY(int h, int c) {
		this.h = h;
		this.c = c;
	}
}
