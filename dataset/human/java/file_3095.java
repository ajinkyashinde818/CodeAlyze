import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] a = new int[m];
		int[] b = new int[m];
		boolean [] fromOne = new boolean[n];
		boolean[] possible = new boolean[n];
		for(int i = 0; i < m; i++) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			if(a[i] == 1 || b[i] == 1) fromOne[Math.max(a[i], b[i]) - 1] = true;
			if(a[i] == n || b[i] == n) possible[Math.min(a[i], b[i]) - 1] = true;
		}
		for(int i = 0; i < n; i++) {
			if(fromOne[i] == true && possible[i] == true) {
				System.out.println("POSSIBLE");
				return;
			}
		}
		System.out.println("IMPOSSIBLE");
	}
}
