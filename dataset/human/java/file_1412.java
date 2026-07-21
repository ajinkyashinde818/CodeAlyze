import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		char[][] a = new char[n][];
		for (int i = 0; i < n; i++)
			a[i] = sc.next().toCharArray();
		
		char[][] b = new char[m][];
		for (int i = 0; i < m; i++)
			b[i] = sc.next().toCharArray();
		
		String ans = "No";
		outer:
		for (int i = 0; i < n - m + 1; i++) {
			next:
			for (int j = 0; j < n - m + 1; j++) {
				for (int k = 0; k < m; k++) {
					for (int l = 0; l < m; l++) {
						if (a[i + k][j + l] != b[k][l]) continue next;
					}
				}
				ans = "Yes";
				break outer;
			}
		}
		
		System.out.println(ans);
		sc.close();
	}
	
}
