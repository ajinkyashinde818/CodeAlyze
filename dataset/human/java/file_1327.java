import java.util.Scanner;

public class Main {
	public static void main(String[] args)  {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		char[][] a = new char[n][n];
		char[][] b = new char[m][m];
		for(int i = 0; i < n; i++) {
			a[i] = sc.next().toCharArray();
		}
		for(int i = 0; i < m; i++) {
			b[i] = sc.next().toCharArray();
		}
		sc.close();
		int count = 0;
		for(int i = 0; i <= n-m; i++) {
			for(int j = 0; j <= n-m; j++) {
				if(a[i][j] == b[0][0]) {
					for(int k = 0; k < m; k++) {
						for(int p = 0; p < m; p++) {
							if(a[i+k][j+p] == b[k][p]) {
								count++;
							}
						}
					}
					if(m*m == count) {
						System.out.println("Yes");
						return;
					}
					count = 0;
				}
			}
		}
		System.out.println("No");
		}
}
