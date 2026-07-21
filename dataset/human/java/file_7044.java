import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int N = sc.nextInt();
		int[] A = new int[N];
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
		}
		sc.close();

		// 最長を除くように動く
		int MAX = 0;
		for (int i = 1; i < N; i++) {
			int d = A[i] - A[i - 1];
			MAX = Math.max(MAX, d);
		}
		// 一周回った差分
		int diff = K - A[N - 1] + A[0];
		if (diff > MAX) {
			MAX = diff;
		}

		System.out.println(K - MAX);
	}
}
