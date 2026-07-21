import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		long A = scan.nextInt();
		long B = scan.nextInt();

		System.out.println(lcm(A,  B));
	}

	private static long gcd(long m, long n) {
		// 入れ替え
		if(m < n) {
			return gcd(n, m);
		}
		if(n == 0) {
			return m;
		}
		return gcd(n , m % n);
	}

	private static long lcm(long m, long n) {
		return m * n / gcd(m, n);
	}

}
