import java.util.Scanner;

public class Main {
	static int n;
	static int m;
	static int c;
	static int d;
	static String A;
	static String B;
	static char[][] a;
	static char[][] b;
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		m = scan.nextInt();
		a = new char[n][n];
		b = new char[m][m];
		for (int i = 0; i < n; i++) {
			A = scan.next();
			for (int j = 0; j < n; j++) {
				a[i][j] = A.charAt(j);
			}
		}
		for (int i = 0; i < m; i++) {
			B = scan.next();
			for (int j = 0; j < m; j++) {
				b[i][j] = B.charAt(j);
			}
		}
		for (c = 0; c <= n-m; c++) {
			for (d = 0; d <= n-m; d++) {
				if (search()) {
					System.out.println("Yes");
					return;
				}
			}
		}
		System.out.println("No");
	}
	static boolean search() {
		for (int k = 0; k < m; k++) {
			for (int l = 0; l < m; l++) {
				if (a[c+k][d+l] != b[k][l]) {
					return false;
				}
			}
		}
		return true;
	}
}
