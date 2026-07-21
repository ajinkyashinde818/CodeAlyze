import java.util.*;

public class Main {
	Scanner sc = new Scanner(System.in);
	final int MOD = 1000000007;
	final int MAX = Integer.MAX_VALUE;
	final long LMAX = Long.MAX_VALUE;
	int LEN = 0;

	void doIt() {
		long a = sc.nextLong();
		long b = sc.nextLong();
		System.out.println(a * b / gcd(a , b));
	}

	long gcd(long a, long b) {
		return (b != 0) ? gcd(b, a % b) : a;
	}
	
	public static void main(String[] args) {
		new Main().doIt();
	}
	
}
