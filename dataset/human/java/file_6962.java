import java.util.Arrays;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int k = scanner.nextInt();
		int n = scanner.nextInt();
		int[] a = new int[n+1];
		int min = Integer.MAX_VALUE;
		for(int i=0; i<n; i++) {
			a[i] = (scanner.nextInt())%k;
		}
		a[n] = Integer.MAX_VALUE;
		a[n] = k+a[0];

		for(int i=0; i<n; i++) {
			min = Math.min(min, k - a[i+1] + a[i]);
		}

		System.out.println(min);
	}
}
