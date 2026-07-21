import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextInt();
		long b = sc.nextInt();
		long gcd = gcd(a,b);
		System.out.println(a*b/gcd);
		sc.close();
	}
	static long gcd (long a, long b) {
		if(b > a) return gcd(b,a);
		if(b == 0) return a;
		return gcd(b, a%b);
	}
}
