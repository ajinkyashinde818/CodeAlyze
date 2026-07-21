import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
		}
		long[] X = new long[N];
		long[] Y = new long[N];

		Y[0] = -A[0];
		X[0] = A[0];
		for (int i = 1; i < N - 1; i++) {
			long x1 = X[i-1];
			long y1 = Y[i-1];
			Y[i] = Math.max(-A[i] + x1, A[i] + y1);
			X[i] = Math.max(A[i] + x1, -A[i] + y1);
		}
		long x = A[N-1] + X[N-2];
		long y = -A[N-1] + Y[N-2];

		System.out.println(Math.max(x, y));
	}
}
