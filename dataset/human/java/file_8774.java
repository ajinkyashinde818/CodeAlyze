import java.io.*;
import java.util.Scanner;


public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();

		int cnt = 0;
		for (int i = Math.min(a, b); i > 0; i--) {
			if (a % i == 0 && b % i == 0) {
				cnt++;
			}
			
			if (cnt == k) {
				pr.println(i);
				break;
			}
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

	static class Printer extends PrintWriter {
		Printer(OutputStream out) {
			super(out);
		}
	}
}
