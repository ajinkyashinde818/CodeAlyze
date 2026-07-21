import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String str[] = br.readLine().split(" ");

		int n = Integer.parseInt(str[0]);
		int m = Integer.parseInt(str[1]);

		String a[][] = new String[n][n];
		String b[][] = new String[m][m];

		for (int i = 0; i < n; i++) {
			str = br.readLine().split("");
			for (int j = 0; j < n; j++) {
				a[i][j] = str[j];
			}
		}

		for (int i = 0; i < m; i++) {
			str = br.readLine().split("");
			for (int j = 0; j < m; j++) {
				b[i][j] = str[j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (solve(j, i, a, b)) {
					System.out.println("Yes");
					return;
				}
			}
		}
		System.out.println("No");
	}

	static boolean solve(int sx, int sy, String a[][], String b[][]) {
		for (int i = sy; i < sy + b.length; i++) {
			for (int j = sx; j < sx + b.length; j++) {
				if (i >= 0 && i < a.length && j >= 0 && j < a.length) {
					if (!a[i][j].equals(b[i - sy][j - sx])) {
						return false;
					}
				} else {
					return false;
				}
			}
		}
		return true;
	}
}
