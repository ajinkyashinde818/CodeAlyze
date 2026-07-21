import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		int A = sc.nextInt();
		int B = sc.nextInt();

		sc.close();

		out.println(lcm(A, B));

	}

	// 最大公約数
	private static long gcd(long a, long b) {
		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}

	// 最小公倍数
	private static long lcm(long a, long b) {
		return (a / gcd(a, b)) * b; // a*bがオーバーフローしないように
	}

	public static void main(String[] args) {
		new Main()._main(args);
	}
}
