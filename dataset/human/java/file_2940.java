import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] a = new int[m];
		int[] b = new int[m];
		for(int i = 0 ; i < m ; i++) {
			a[i] = sc.nextInt() - 1;
			b[i] = sc.nextInt() - 1;
		}
		boolean[] bool1 = new boolean[n];
		boolean[] bool2 = new boolean[n];
		for(int i = 0 ; i < m ; i++) {
			if(a[i] == 0) bool1[b[i]] = true;
			if(b[i] == n - 1) bool2[a[i]] = true;
		}
		for(int i = 0 ; i < n ; i++) {
			if(bool1[i] && bool2[i]) {
				System.out.println("POSSIBLE");
				return;
			}
		}
		System.out.println("IMPOSSIBLE");
	}
}
