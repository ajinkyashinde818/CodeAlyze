import java.util.Scanner;

class Solver {
	static final Solver INSTANCE = new Solver();

	void solve(Scanner sc) {
		int N = sc.nextInt();
		int M = sc.nextInt();
		String[] A = new String[N];
		String[] B = new String[M];
		for (int i = 0; i < N; i++) {
			A[i] = sc.next();
		}
		for (int i = 0; i < M; i++) {
			B[i] = sc.next();
		}
		for (int i = 0; i < N - M + 1; i++) {
			block:
			for (int index = A[i].indexOf(B[0]); index < N && index >= 0; index = A[i].indexOf(B[0], index + 1)) {
				for (int j = 1; j < M; j++) {
					if (!A[i + j].substring(index).startsWith(B[j])) continue block;
				}
				System.out.println("Yes");
				return;
			}
		}
		System.out.println("No");
	}
}

class Main {
	public static void main(String... args) {
		Scanner in = new Scanner(System.in);

		Solver.INSTANCE.solve(in);

		in.close();
	}
}
