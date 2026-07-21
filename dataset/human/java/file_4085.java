import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		int N = sc.nextInt();

		int[] A = nextIntArray1origin(sc, N);
		int[] B = nextIntArray1origin(sc, N);
		int[] C = nextIntArray1origin(sc, N - 1);

		sc.close();

		int prev = -100;

		int ans = 0;
		for (int i = 1; i <= N; i++) {
			int d = A[i];
			ans += B[d];

			if (d == prev + 1) {
				ans += C[prev];
			}
			prev = d;
		}

		out.println(ans);

	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

	@SuppressWarnings("unused")
	private int[] nextIntArray1origin(Scanner sc, int n) {
		int[] result = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			result[i] = sc.nextInt();
		}
		return result;
	}
}
