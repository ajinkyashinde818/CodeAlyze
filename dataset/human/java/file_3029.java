import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		boolean f = false;
		int n = scan.nextInt();
		int m = scan.nextInt();
		boolean[] A = new boolean[n];
		boolean[] B = new boolean[n];
		Arrays.fill(A, false);
		Arrays.fill(B, false);
		int[] a = new int[m];
		int[] b = new int[m];
		for (int i = 0; i < m; i++) {
			a[i] = scan.nextInt();
			b[i] = scan.nextInt();
		}
		
		for (int i = 0; i < m; i++) {
			if (a[i] == n) {
				A[b[i]] = true;
			} else if (b[i] == n) {
				A[a[i]] = true;
			} else if (a[i] == 1) {
				B[b[i]] = true;
			} else if (b[i] == 1) {
				B[a[i]] = true;
			}
		}
		
		for (int i = 0; i < n; i++) {
			if (A[i] == true && B[i] == true) {
				f = true;
				break;
			}
		}
		
		if (f) {
			System.out.println("POSSIBLE");
		} else {
			System.out.println("IMPOSSIBLE");
		}
	}
}
