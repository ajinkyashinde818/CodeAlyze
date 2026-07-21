import java.io.*;
import java.util.*;


public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		int n = sc.nextInt();
		int m = sc.nextInt();

		char[][] a = new char[n][];
		for (int i = 0; i < n; i++) {
			a[i] = sc.next().toCharArray();
		}
		char[][] b = new char[m][];
		for (int i = 0; i < m; i++) {
			b[i] = sc.next().toCharArray();
		}

		for (int i = 0; i + m - 1 < n; i++) {
			for (int j = 0; j + m - 1 < n; j++) {
				if (isOK(i, j, a, b)) {
					pr.println("Yes");
					return;
				}
			}
		}

		pr.println("No");
	}

	private static boolean isOK(int x, int y, char[][] a, char[][] b) {
		int m = b.length;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (a[x + i][y + j] != b[i][j]) {
					return false;
				}
			}
		}

		return true;
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
