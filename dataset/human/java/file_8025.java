import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		System.out.println(solve());
	}

	public static long solve() {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		return lcm(A, B);
	}

	public static long gcd(long a, long b) {
		if (a == 0 || b == 0) {
			return a + b;
		} else {
			long absA = Math.abs(a);
			long absB = Math.abs(b);
			long mx = Math.max(absA, absB);
			long mn = Math.min(absA, absB);
			return gcd(mx % mn, mn);
		}
	}

	public static long lcm(long a, long b) {
		if (a == 0 || b == 0)
			return 0;
		else {
			long gcd = gcd(a, b);
			return Math.abs(a * b) / gcd;
		}
	}
}
