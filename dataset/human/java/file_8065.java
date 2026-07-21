import java.util.Scanner;

public class Main {

	public static long Gcd(long m, long n) {
		if(m < n) {
			long tmp = m;
			m = n;
			n = tmp;
		}
		if(m % n == 0)
			return n;
		else {
			m %= n;
			return Gcd(m, n);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextInt();
		long b = sc.nextInt();
		long ans = a * b / (Gcd(a, b));
		System.out.println(ans);
	}

}
