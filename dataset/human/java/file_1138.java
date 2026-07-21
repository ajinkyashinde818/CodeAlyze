import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		long[] a = new long[n];
		long[] s = new long[n];
		long min = Long.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			a[i] = scan.nextInt();
		}
		
		s[0] = a[0];
		for (int i = 1; i < n; i++) {
			s[i] = s[i-1] + a[i];
		}
		
		for (int i = 0; i < n-1; i++) {
			long S = s[i];
			long A = s[n-1] - s[i];
			long dif = Math.abs(S-A);
			if (min > dif) {
				min = dif;
			}
		}
		
		System.out.println(min);
	}
}
