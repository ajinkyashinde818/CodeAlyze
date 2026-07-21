import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		int N = input.nextInt();
		int M = input.nextInt();
		int X = input.nextInt();

		int minCost = -1;

		int[][] bookList = new int[N][M + 1];

		//参考書リストの作成
		for(int i = 0; i < N; i++) {
			for(int m = 0; m <= M ;m++) {

				int n = input.nextInt();
				bookList[i][m] = n;

			}
		}
		input.close();

		for(int bit = 0; bit < (1 << N); bit++) {
			int[] buyList = new int[M +1];
			int flag = 0;

			for(int i =0;i < N; ++i ) {
				if((1 & bit >> i) == 1) {

					for(int m = 0; m < M + 1; m++) {

						buyList[m] = buyList[m] + bookList[i][m];
						//System.out.println(buyList[m]);

					}
				}
			}
			for(int m =1; m < M + 1; m++) {

				if(buyList[m] < X) {

					flag = 1;

				}

			}
			//System.out.println(buyList[0]);

			if(((minCost > 0) & (buyList[0] < minCost) & flag == 0) | ((minCost == -1) & flag == 0) ) {
				minCost = buyList[0];
			}
		}

		System.out.println(minCost);

	}
}
