import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int A = in.nextInt();
		int B = in.nextInt();
		System.out.println(lcm(A, B));
		in.close();
	}

	static long gcd(long x, long y) {
		if (x < y) {
			long tmp = y;
			y = x;
			x = tmp;
		}
		if (y == 0) {
			return x;
		}
		return gcd(x % y, y);
	}

	static long lcm(long m, long n) {
		return m * n / gcd(m, n);
	}
}
