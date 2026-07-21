import java.io.*;
import java.util.*;

class Main {
	static final String YES = "Yes";
	static final String NO = "No";

	static char[][] A, B;

	public static void main(String[] args) throws Exception {
		final Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		A = new char[N][N];
		for (int i = 0; i < N; i++) {
			A[i] = sc.next().toCharArray();
		}
		B = new char[M][M];
		for (int i = 0; i < M; i++) {
			B[i] = sc.next().toCharArray();
		}

		for (int i = 0; i < N; i++) {
			if (N - M < i) break;
			for (int j = 0; j < N; j++) {
				if (N - M < j) break;
				if (check(i, j, M)) {
					System.out.println(YES);
					return;
				}
			}
		}

		System.out.println(NO);
	}

	private static boolean check(int i, int j, int M) {
		for (int k = 0; k < M; k++) {
			for (int l = 0; l < M; l++) {
				if (A[i + k][j + l] != B[k][l]) {
					return false;
				}
			}
		}
		return true;
	}
}
