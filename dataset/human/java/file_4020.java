import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		int[] B = new int[N];
		int[] C = new int[N - 1];
		long ans = 0;
		for (int i = 0; i < N; ++i) {
			A[i] = sc.nextInt();
			--A[i];
		}
		for (int i = 0; i < N; ++i) {
			B[i] = sc.nextInt();
			ans += B[i];
		}
		for (int i = 0; i < N - 1; ++i) {
			C[i] = sc.nextInt();
		}
		for (int i = 0; i < N - 1; ++i) {
			if (A[i] + 1 == A[i + 1]) {
				ans += C[A[i]];
			}
		}
		System.out.println(ans);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}
