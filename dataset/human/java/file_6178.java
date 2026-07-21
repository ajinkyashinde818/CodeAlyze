import java.io.*;
import java.util.*;


public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		int k = sc.nextInt();
		int s = sc.nextInt();

		long ret = 0;
		for (int x = 0; x <= Math.min(k, s); x++) {
			for (int y = 0; y <= Math.min(k, s - x); y++) {
				if (s - x - y <= k) {
					ret++;
				}
			}
		}

		pr.println(ret);
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
