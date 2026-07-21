import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		long a = scan.nextInt();
		long b = scan.nextInt();

		System.out.println((a * b) / gcd(a , b));

	}
	public static long gcd(long a , long b) {
		if(b == 0) {
			return a;
		}

		return gcd(b , a % b);
	}
}
