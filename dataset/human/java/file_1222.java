import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long a[] = new long[N];
		long x[] = new long[N];
		long y[] = new long[N];
		long sum = 0;
		for(int i = 0; i < N; i++) {
			a[i] = sc.nextLong();
			if(i == 0) {
				x[i] = a[0];
			} else {
				x[i] += a[i] + x[i - 1];
			}
		}
		sum = x[N - 1];
		long ans = Long.MAX_VALUE;
		for(int i = 1; i < N - 1; i++) {
			y[i] = sum - x[i];
			ans = Math.min(ans, Math.abs(x[i] - y[i]));
		}
		if(N == 2) {
			ans = Math.abs(a[0] - a[1]);
		}
		System.out.println(ans);
	}
}
