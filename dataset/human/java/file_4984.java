import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		String S = sc.next();
		int Q = sc.nextInt();

		boolean b = true; // 今、Sが元の順のときtrue

		StringBuffer head = new StringBuffer();
		StringBuffer tail = new StringBuffer();

		for (int i = 0; i < Q; i++) {
			int T = sc.nextInt();

			if (T == 1) {
				b = !b;

			} else {
				int F = sc.nextInt();
				String c = sc.next();
				if (F == 1) {
					if (b) {
						head.append(c);
					} else {
						tail.append(c);
					}
				} else {
					if (b) {
						tail.append(c);
					} else {
						head.append(c);
					}
				}
			}
		}

		sc.close();
		head.reverse().append(S).append(tail).toString();

		if (b) {
			out.println(head.toString());
		} else {
			out.println(head.reverse().toString());
		}

	}

	public static void main(String[] args) {
		new Main()._main(args);
	}
}
