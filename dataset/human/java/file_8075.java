import java.util.*;

public class Main {
	void solve() {
		Scanner scan = new Scanner(System.in);
		long a = scan.nextInt();
		long b = scan.nextInt();
		System.out.println(lcm(a, b));
		scan.close();
	}
	
	long lcm(long a, long b) {
		return a * b / gcd(a, b);
	}
	
	long gcd(long a, long b) {
		if(a % b == 0) return b;
		return gcd(b, a % b);
	}
	
	public static void main(String[] args) {
		new Main().solve();
	}
}
