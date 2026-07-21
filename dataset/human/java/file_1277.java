import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		try(Scanner sc = new Scanner(System.in)) {
			int n = sc.nextInt();
			int[] a = new int[n];
			long sum = 0;
			for(int i = 0 ; i < n ; i++) {
				a[i] = sc.nextInt();
				sum += a[i];
			}
			long now = 0;
			long min = Long.MAX_VALUE;
			for(int i = 0 ; i < n - 1 ; i++) {
				now += a[i];
				min = Math.min(min, Math.abs(now - (sum - now)));
			}
			System.out.println(min);
		}

	}

}
