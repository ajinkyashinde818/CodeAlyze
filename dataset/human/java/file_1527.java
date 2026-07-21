import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		String[][] A = new String[N][N];
		String[][] B = new String[M][M];
		for (int i = 0; i < N; i++) {
			String str = sc.next();
			String[] temp = new String[N];
			for (int j = 0; j < N; j++) {
				temp[j] = String.valueOf(str.charAt(j));
			}
			A[i] = temp;
		}
		for (int i = 0; i < M; i++) {
			String str = sc.next();
			String[] temp = new String[M];
			for (int j = 0; j < M; j++) {
				temp[j] = String.valueOf(str.charAt(j));
			}
			B[i] = temp;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (A[i][j].equals(B[0][0])) {
					int cnt = 0;
					for (int k = 0; k < M; k++) {
						for (int l = 0; l < M; l++) {
							if (i + k < N && j + l < N) {
								if (A[i + k][j + l].equals(B[k][l])) {
									cnt++;
								}
							}
						}
					}
					if (cnt == M * M) {
						System.out.println("Yes");
						return;
					}
				}

			}
		}
		System.out.println("No");

	}

}
