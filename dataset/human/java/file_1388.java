import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		char[][] a = new char[n][n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.next().toCharArray();
		}
		char[][] b = new char[m][m];
		for (int i = 0; i < m; i++) {
			b[i] = sc.next().toCharArray();
		}
		sc.close();

		for (int i = 0; i <= n - m; i++) {
			for (int j = 0; j <= n - m; j++) {
				boolean flg = true;
				for (int x = 0; x < m; x++) {
					for (int y = 0; y < m; y++) {
						if (a[i + x][j + y] != b[x][y]) {
							flg = false;
							break;
						}
					}
				}
				if (flg) {
					System.out.println("Yes");
					return;
				}
			}
		}
		System.out.println("No");
	}
}
