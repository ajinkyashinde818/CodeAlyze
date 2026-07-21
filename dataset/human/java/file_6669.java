import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] A = new long[N];
		long[] d = new long[N];
		long sum = 0;
		long d_sum = 0;
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
			sum += A[i];
			if (i > 0) {
				d[i] = A[i] - A[i - 1];
				d_sum += d[i];
			}
		}
		d[0] = A[0] - A[N - 1];
		d_sum += d[0];
		sc.close();

		long m = ((long) N) * ((long) (N + 1)) / 2L;
		String ans = "YES";
		long div = 0;
		long[] a = new long[N];
		long chk = 0;
		if ((sum % m) != 0 || d_sum != 0L) {
			ans = "NO";
		} else {
			long cnt = sum / m;
			for (int i = 0; i < N; i++) {
				d[i] -= cnt;
				if (((-d[i]) % N) != 0 || d[i] > 0) {
					ans = "NO";
					break;
				} else {
					a[i] = (-d[i]) / N;
					div += a[i];
					int mul = (N - i + 1) % N;
					mul = mul == 0 ? N : mul;
					chk += a[i] * mul;
				}
			}
			if (div != cnt) {
				ans = "NO";
			}
			for (int i = 0; i < N; i++) {
				if (chk != A[i]) {
					ans = "NO";
				}
				chk += (div - N * a[(i + 1) % N]);
			}
		}
		System.out.println(ans);
	}
}
