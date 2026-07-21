import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		int d = gcd(a, b);
		int x = d;
		for (; ; d--) {
			if (x % d == 0) {
				k--;
				if (k == 0) {
					break;
				}
			}
		}
		System.out.println(d);
	}
	
	static int gcd(int x, int y) {
		if (x % y == 0) {
			return y;
		}
		return gcd(y, x % y);
	}
}
