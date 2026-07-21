import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		long[] a = new long[N];
		for (int i = 0; i < N; i++) {
			a[i] = in.nextLong();
		}
		long[] b = new long[N + 1];
		for (int i = 0; i < N; i++) {
			b[i + 1] = b[i] + a[i];
		}
		long ans = Long.MAX_VALUE;
		for (int i = 0; i < N - 1; i++) {
			ans = Math.min(ans, Math.abs(b[i + 1] - (b[b.length - 1] - b[i + 1])));
		}
		System.out.println(ans);
		in.close();
	}
}
