import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int m = scan.nextInt();
		String[] str_a = new String[n];
		String[] str_b = new String[m];
		String[][] a = new String[n][n];
		String[][] b = new String[m][m];
		int i = 0;
		int j = 0;
		for(i = 0; i < n; i++) {
			str_a[i] = scan.next();
		}
		for(i = 0; i < m; i++) {
			str_b[i] = scan.next();
		}
		String message = "No";
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				a[i][j] = str_a[i].charAt(j) + "";
			}
		}
		for(i = 0; i < m; i++) {
			for(j = 0; j < m; j++) {
				b[i][j] = str_b[i].charAt(j) + "";
			}
		}
		a:for(i = 0; i + m <= n; i++) {
			for(j = 0; j + m <= n; j++) {
				b:for(int k = 0; k < m; k++) {
					for(int l = 0; l < m; l++) {
						if(a[i + k][j + l].equals(b[k][l])) {
						} else {
							break b;
						}
						if((k == m -1) && (l == m - 1)) {
							message = "Yes";
							break a;
						}
					}
				}
			}
		}
		System.out.println(message);
	}
}
