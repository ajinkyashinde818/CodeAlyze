import java.util.Arrays;
import java.util.Scanner;

final class Solver {
	static final Solver INSTANCE = new Solver();

	void solve(Scanner sc) {
		int K = sc.nextInt();
		int N = sc.nextInt();
		int[] A = new int[N];
		Arrays.setAll(A, $ -> sc.nextInt());
		int max = (K - A[A.length - 1]) + A[0];
		for (int i = 1; i < A.length; i++) {
			max = Math.max(A[i] - A[i - 1], max);
		}
		System.out.println(K - max);
	}
}

class Main {
	public static void main(String... args) {
		Scanner in = new Scanner(System.in);

		Solver.INSTANCE.solve(in);

		in.close();
	}
}
