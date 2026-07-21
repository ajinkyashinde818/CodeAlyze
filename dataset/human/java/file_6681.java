import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
	static long N;
	static long[] A;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextLong();
		A = new long[(int) N];
		long s = 0;
		for (int i = 0; i < N; ++i) {
			A[i] = sc.nextLong();
			s += A[i];
		}
		long all = N * (N + 1) / 2;
		if (s % all != 0) {
			System.out.println("NO");
			return;
		}
		long K = (s / all);
		long[] diff = new long[(int) N];
		for (int i = 0; i < N; ++i) {
			diff[i] = A[(int) ((i + 1) % N)] - A[i];
		}
		for (int i = 0; i < N; ++i) {
			diff[i] -= K;
			if (diff[i] > 0 || (-diff[i]) % N != 0) {
				System.out.println("NO");
				return;
			}
		}

		System.out.println("YES");

	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}
