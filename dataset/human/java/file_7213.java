import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long k = sc.nextInt();
		int n = sc.nextInt();
		long ans = 0;
		long max = 0;
		long[] a = new long[n];
		for(int i = 0; i < n; i++) {
			a[i] = sc.nextLong();
		}
		for(int i = 0; i < n; i++) {
			if(i < n - 1) {
				ans += a[i + 1] - a[i];
				max = Math.max(max, a[i + 1] - a[i]);
			} else {
				ans += k + a[0] - a[i];
				max = Math.max(max, k + a[0] - a[i]);
			}
		}
		ans -= max;
		System.out.println(ans);

	}

}
