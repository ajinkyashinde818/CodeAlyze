import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();
		int M = scan.nextInt();
		int X = scan.nextInt();
		int[] C = new int[N];
		int[][] A = new int[N][M];
		int answer = Integer.MAX_VALUE;

		for (int i = 0; i < N; i++) {
			C[i] = scan.nextInt();
			for (int k = 0; k < M; k++) {
				A[i][k] = scan.nextInt();
			}
		}

		for (int i = 0; i < (1<<N); i++) {

			int price = 0;
			int[] values = new int[M];

			for (int j = 0; j < N; j++) {
				if ((1&i>>j) == 1) {
					price += C[j];

					for (int k = 0; k < M; k++) {
						values[k] += A[j][k];
					}
				}
			}

			boolean flag = true;
			for (int k = 0; k < M; k++) {
				if (values[k] < X) {
					flag = false;
					continue;
				}
			}
			if (flag) answer = Math.min(answer, price);
		}

		System.out.println(answer == Integer.MAX_VALUE ? -1 : answer);
 	}
}
