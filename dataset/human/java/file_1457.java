import java.util.Scanner;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int m = scanner.nextInt();
		char[][] a = new char[n][n];
		char[][] b = new char[m][m];
		String ans = "";

		for (int i = 0; i < n; i++) {
			String tmp = scanner.next();
			for (int j = 0; j < n; j++) {
				a[j][i] = tmp.charAt(j);
			}
		}

		for (int i = 0; i < m; i++) {
			String tmp = scanner.next();
			for (int j = 0; j < m; j++) {
				b[j][i] = tmp.charAt(j);
			}
		}

		for (int i = 0; i < n - m + 1; i++) {
			for (int j = 0; j < n - m + 1; j++) {
				out_of_loop: for (int s = 0; s < m; s++) {
					for (int k = 0; k < m; k++) {
						if (a[j + k][i + s] != b[k][s]) {
							ans = "No";
							break out_of_loop;
						} else {
							ans = "Yes";
						}
					}
				}
				if (ans.equals("Yes")) {
					System.out.println(ans);
					return;
				}
			}
		}

		System.out.println(ans);

	}
}
