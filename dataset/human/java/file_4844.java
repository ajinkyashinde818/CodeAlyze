import java.io.InputStream;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	long f(long n) {
		if (n < 2) {
			return 1;
		} else {
			return n * f(n - 2);
		}
	}

	long calc(long n) {
		if (n % 2 != 0) {
			return 0;
		}
		long result = n / 10;

		for (int i = 1; i < 1000; i++) {
			long x = (long) Math.pow(5, i) * 10;
			if (x > n) {
				break;
			}
			result += n / x;
		}
		return result;
	}

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		long N = sc.nextLong();

		sc.close();

		out.println(calc(N));

//		for(int i=0;i<100;i++) {
//			System.err.println(i + " : " + f(i));
//		}
//		System.err.println("--");

//		calc(250);

//		for(int i=0;i<10000;i++) {
//			BigDecimal d = f2(new BigDecimal(i));
////			System.err.println(i  + " : " + cntZero(d.toPlainString()));//+ " : " + d);
//			System.err.println(i  + " : " + cntZero(d.toPlainString()) + " : " + calc(i)  );//+ " : " + d);
//		}
//		System.err.println("--");		

	}

	BigDecimal f2(BigDecimal n) {
		if (n.compareTo(new BigDecimal(2)) < 0) {
			return BigDecimal.ONE;
		} else {
			return n.multiply(f2(n.subtract(new BigDecimal(2))));
		}
	}

	long cntZero(String s) {
		if (s.isEmpty()) {
			return 0;
		}
		if (s.endsWith("0")) {
			return 1 + cntZero(s.substring(0, s.length() - 1));
		} else {
			return 0;
		}
	}

	public static void main(String[] args) {
		new Main()._main(args);
	}
}
