import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		long A = scn.nextInt(), B = scn.nextInt();
		long gcd = gcd(A,B);
		System.out.println(A/gcd*B);
	}
	public static long gcd(long a,long b) {
		while(a%b!=0) {
			long buf = a%b;
			a = b;
			b = buf;
		}
		return b;
	}
}
