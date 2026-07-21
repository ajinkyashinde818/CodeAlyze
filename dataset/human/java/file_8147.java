import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		sc.close();

		BigInteger ba = BigInteger.valueOf(a);
		BigInteger bb = BigInteger.valueOf(b);
		BigInteger gcd = ba.gcd(bb);
		System.out.println(ba.multiply(bb).divide(gcd).toString());
	}
}
