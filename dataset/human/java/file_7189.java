import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		long K = sc.nextLong();
		int N = sc.nextInt();

		long[] A = nextLongArray(sc, N);

		sc.close();

		long[] b = new long[N];
		b[0] = A[0] + K - A[N - 1];
		for (int i = 1; i < N; i++) {
			b[i] = A[i] - A[i - 1];
		}

		Arrays.sort(b);

		long ans = 0;
		for (int i = 0; i < N - 1; i++) {
			ans += b[i];
		}

		out.println(ans);

	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

	@SuppressWarnings("unused")
	private long[] nextLongArray(Scanner sc, int n) {
		long[] result = new long[n];
		for (int i = 0; i < n; i++) {
			result[i] = sc.nextLong();
		}
		return result;
	}
}
