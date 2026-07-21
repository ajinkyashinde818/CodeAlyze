import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int X = sc.nextInt();
		int[] C = new int[N];
		int[][] A = new int[N][M];
		int[] S = new int[M];
		int ans = 0;
		for (int j = 0; j < M; j++) {
			S[j] = 0;
		}
		for (int i = 0; i < N; i++) {
			C[i] = sc.nextInt();
			for (int j = 0; j < M; j++) {
				A[i][j] = sc.nextInt();
				S[j] += A[i][j];
			}
			ans += C[i];
		}

		if (!overX(S, X)) {
			System.out.println("-1");
			return;
		}

		for (int i = 0; i < Math.pow(2, N); i++) {
			for (int j = 0; j < M; j++) {
				S[j] = 0;
			}
			String bin = Integer.toBinaryString(i);
			bin = String.format("%" + N + "s", bin).replace(" ", "0");
			int cost = 0;
			for (int j = 0; j < N; j++) {
				if (bin.charAt(j) == '1') {
					for (int k = 0; k < M; k++) {
						S[k] += A[j][k];
					}
					cost += C[j];
				}
			}
			if (overX(S, X) && cost < ans) {
				ans = cost;
			}
		}
		System.out.println(ans);
	}

	public static boolean overX(int[] S, int X) {
		for (int i = 0; i < S.length; i++) {
			if (S[i] < X) {
				return false;
			}
		}
		return true;
	}

}
