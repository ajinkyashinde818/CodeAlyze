import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		int N = sc.nextInt();
		int R = sc.nextInt();

		sc.close();

		if (N >= 10) {
			out.println(R);
		} else {
			out.println(R + (100 * (10 - N)));
		}

	}

	public static void main(String[] args) {
		new Main()._main(args);
	}
}
