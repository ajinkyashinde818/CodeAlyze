import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		int N = sc.nextInt();
		int[] A = new int[N];

		int c = 0;
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
			if (A[i] < 0) {
				c++;
			}
		}

		for (int i = 0; i < N; i++) {
			A[i] = Math.abs(A[i]);
		}
		Arrays.sort(A);

		long ans;
		if (c % 2 == 0) {
			ans = 0;
			for (int i = 0; i < N; i++) {
				ans += A[i];
			}
		} else {
			ans = -A[0];
			for (int i = 1; i < N; i++) {
				ans += A[i];
			}

		}
		out.println(ans);

		sc.close();

	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}
