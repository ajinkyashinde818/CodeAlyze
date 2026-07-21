import java.util.Scanner;

public class Main {
	//java11

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int M = sc.nextInt();
		int X = sc.nextInt();

		int[] C = new int[N];
		int[][] A = new int[N][M];
		long C_sum = 0;
		long[] A_sum = new long[M];
		for(int i=0; i<N; i++) {
			C[i] = sc.nextInt();
			C_sum += C[i];

			for(int j=0; j<M; j++) {
				A[i][j] = sc.nextInt();
				A_sum[j] += A[i][j];
			}
		}

		//すべて選ぶ
		for(int i=0; i<M; i++) {
			if(A_sum[i] < X) {
				System.out.println(-1);
				return;
			}
		}

		long ans = C_sum;
		for(int i=0; i<(1<<N); i++) {
			long sum = C_sum;
			long[] Ai_sum = new long[M];
			System.arraycopy(A_sum, 0, Ai_sum, 0, A_sum.length);
			for(int j=0; j<N; j++) {
				//選択しない
				if((1 & (i >> j)) == 0) {
					sum -= C[j];
					for(int k=0; k<M; k++) {
						Ai_sum[k] -= A[j][k];
					}
				}
			}

			boolean ok = true;
			for(int j=0; j<M; j++) {
				if(Ai_sum[j] < X) {
					ok = false;
					break;
				}
			}

//			System.out.println("ans: " + ans);
			if(ok) {
				ans = Math.min(ans, sum);
//				System.out.println("ans_change: " + ans);
			}
		}

		System.out.println(ans);

	}

}
