import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		sc.close();

		long sum = 0;
		int cnt = 0;
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			if (a[i] < 0) {
				cnt++;
			}
			int abs = Math.abs(a[i]);
			sum += abs;
			min = Math.min(min, abs);
		}
		if (cnt % 2 == 1) {
			System.out.println(sum - 2 * min);
		} else {
			System.out.println(sum);
		}
	}
}
