import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		int N = sc.nextInt();
		int[] a = nextIntArray(sc, N);

		sc.close();

		long[] left = new long[N];

		left[0] = a[0];
		for (int i = 1; i < N; i++) {
			left[i] = left[i - 1] + a[i];
		}

		long[] right = new long[N];
		right[N - 1] = a[N - 1];
		for (int i = N - 2; i >= 0; i--) {
			right[i] = a[i] + right[i + 1];
		}

		long ans = Long.MAX_VALUE;

		for (int i = 0; i < N - 1; i++) {
			ans = Math.min(ans, Math.abs(left[i] - right[i + 1]));
		}

		out.println(ans);

	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

	@SuppressWarnings("unused")
	private int[] nextIntArray(Scanner sc, int n) {
		int[] result = new int[n];
		for (int i = 0; i < n; i++) {
			result[i] = sc.nextInt();
		}
		return result;
	}
}
