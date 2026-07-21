import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();
		char[][] A = new char[N][N];
		char[][] B = new char[N][N];
		for (int i = 0; i < N; i++) {
			String s = in.next();
			A[i] = s.toCharArray();
		}
		for (int i = 0; i < M; i++) {
			String s = in.next();
			B[i] = s.toCharArray();
		}
		String ans = "No";
		for (int i = 0; M <= (N - i); i++) {
			boolean isOk = true;
			for (int j = 0; j < M; j++) {
				for (int j2 = 0; j2 < M; j2++) {
					if (A[j][i + j2] != B[j][j2]) {
						isOk = false;
						break;
					}
				}
				if (!isOk) {
					break;
				}
			}
			if (isOk) {
				ans = "Yes";
				break;
			}
		}
		for (int i = 0; M <= (N - i); i++) {
			boolean isOk = true;
			for (int j = 0; j < M; j++) {
				for (int j2 = 0; j2 < M; j2++) {
					if (A[i + j][j2] != B[j][j2]) {
						isOk = false;
						break;
					}
				}
				if (!isOk) {
					break;
				}
			}
			if (isOk) {
				ans = "Yes";
				break;
			}
		}
		for (int i = 0; M <= (N - i); i++) {
			boolean isOk = true;
			for (int j = 0; j < M; j++) {
				for (int j2 = 0; j2 < M; j2++) {
					if (A[i + j][i + j2] != B[j][j2]) {
						isOk = false;
						break;
					}
				}
				if (!isOk) {
					break;
				}
			}
			if (isOk) {
				ans = "Yes";
				break;
			}
		}
		System.out.println(ans);
		in.close();
	}
}
