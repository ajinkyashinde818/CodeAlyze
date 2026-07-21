import java.util.Scanner;

public class Main {

	static Main instance = new Main();

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		//入力値
		int N = scan.nextInt();
		int M = scan.nextInt();
		int X = scan.nextInt();

		int[][] A = new int[N][M];
		int[] C = new int[N];

		for (int i = 0; i < N; i++) {
			C[i] = scan.nextInt();
			for (int j = 0; j < M; j++) {
				A[i][j] = scan.nextInt();
			}
		}

		//WK変数
		int result = -1;

		//演算
		l1: for (int i = 0; i < Math.pow(2, N); i++) {
			int sum = 0;
			int price = 0;
			for (int j = 0; j < M; j++) {
				sum = 0;
				price = 0;
				for (int i1 = 0; i1 < N; i1++) {
					sum += A[i1][j] * ((int) (i % Math.pow(2, i1 + 1)) / (int) Math.pow(2, i1));
					price += C[i1] * ((int) (i % Math.pow(2, i1 + 1)) / (int) Math.pow(2, i1));
				}

				if (sum < X) {
					continue l1;
				}
			}

			if (price != 0 && (result == -1|| result > price)) {
				result = price;
			}
		}

		//結果出力
		System.out.println(result);
	}
}
