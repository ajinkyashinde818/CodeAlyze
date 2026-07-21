import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ

		Scanner scan = new Scanner(System.in);
		long A = scan.nextInt();
		long B = scan.nextInt();

		long gcd = GCD(A,B);
		long lcm = LCM(A,B,gcd);
		System.out.println(lcm);

	}

public static long GCD(long a, long b) {
	for(long i = a; i > 0; i--) {
		if(a%i == 0 && b%i == 0) {
			return i;
		}
	}
	return 1;
}

public static long LCM(long a, long b, long gcd) {
	return a*b/gcd;
}
}
