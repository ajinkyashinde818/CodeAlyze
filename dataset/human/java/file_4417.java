import java.io.*;
import java.util.Scanner;


public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		int n = sc.nextInt();

		int[] a = new int[n];
		int[] b = new int[n];
		int[] c = new int[n];
		for (int i= 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		for (int i= 0; i < n; i++) {
			b[i] = sc.nextInt();
		}
		for (int i= 0; i < n - 1; i++) {
			c[i] = sc.nextInt();
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				if (a[i] == a[i - 1] + 1) {
					ans += c[a[i - 1] - 1];
				}
			}
			ans += b[a[i] - 1];
		}
		
		pr.println(ans);
	}

	// ---------------------------------------------------
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		pr = new Printer(System.out);
			
		solve();
			
		pr.close();
		sc.close();
	}

	static class Printer extends PrintWriter {
		Printer(OutputStream out) {
			super(out);
		}
	}
}
