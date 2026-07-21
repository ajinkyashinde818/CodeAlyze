import java.io.*;
import java.util.*;


public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		char[] x = sc.next().toCharArray();
		char[] y = sc.next().toCharArray();

		if (x[0] == y[0]) {
			pr.println('=');
		} else if (x[0] < y[0]) {
			pr.println('<');
		} else {
			pr.println('>');
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
