import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] a = new long[n];
		long sum = 0;
		for (int i = 0; i < a.length; i++) {
			a[i] = sc.nextLong();
			sum += a[i];
		}
		
		long min = Long.MAX_VALUE;
		long sum2 = 0;
		for (int i = 0; i < n - 1; i++) {
			sum2 += a[i];
			min = Math.min(min, Math.abs(2 * sum2 - sum));
		}
		
		System.out.println(min);
		
		
	}
}
