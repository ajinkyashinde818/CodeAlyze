import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, m;
		n = sc.nextInt();
		m = sc.nextInt();
		char[][] a = new char[n][n];
		char[][] b = new char[m][m];
		for (int i = 0; i < a.length; i++) {
			a[i] = sc.next().toCharArray();
		}
		for (int i = 0; i < m; i++) {
			b[i] = sc.next().toCharArray();
		}

		boolean match = true;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if(y + m - 1 >= n || x + m - 1 >= n) continue;

				match = true;
				for (int y2 = 0; y2 < m; y2++) {
					for (int x2 = 0; x2 < m; x2++) {
						if(a[y + y2][x + x2] != b[y2][x2]) match = false;
					}
				}
				if(match) {
					System.out.println("Yes");
					return;
				}
			}
		}

		if(!match) {
			System.out.print("No");
		}
	}
}
