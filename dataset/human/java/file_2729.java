import java.io.*;
import java.util.*;


public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		char[] s = sc.next().toCharArray();
		int n = s.length;
		char[] t = sc.next().toCharArray();
		int m = t.length;

		Arrays.sort(s);
		Arrays.sort(t);

		for (int i = 0; i < Math.min(n, m); i++) {
			if (s[i] < t[m - 1 - i]) {
				pr.println("Yes");
				return;
			} else if (s[i] > t[m - 1 - i]) {
				pr.println("No");
				return;
			}
		}

		if (n >= m) {
			pr.println("No");
		} else {
			pr.println("Yes");
		}
	}

	// ---------------------------------------------------
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		pr = new Printer(System.out);

		solve();

		pr.close();
		sc.close();
	}

	private static class Printer extends PrintWriter {
		Printer(PrintStream out) {
			super(out);
		}
	}
}
