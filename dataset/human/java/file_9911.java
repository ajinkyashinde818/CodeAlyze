import java.util.Scanner;

public class Main {

	static int input_N;
	static int input_M;
	static int input_X;


	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		input_N = sc.nextInt();
		input_M = sc.nextInt();
		input_X = sc.nextInt();
		int[][] sankosho = new int[input_N][input_M+1];

		int[] sum = new int[input_M+1];
		int depth = input_N;

		int result = -1;

		for(int i=0;i<input_N;i++) {
			for(int j=0;j<input_M+1;j++) {
				sankosho[i][j] = sc.nextInt();
			}
		}
		sc.close();

		//12冊ある参考書を総当りするコードを書きたい。
		result = serchSankosho(sankosho,sum,result,depth-1);

		// 出力
		System.out.println(result);

	}

	static int serchSankosho(int[][] sankosho,int[] sum,int result,int depth) {

		if(depth < 0) {
			for(int i=1;i<input_M+1;i++) {
				if(sum[i] < input_X ) {
					return result;
				}
			}

			if(sum[0] < result || result < 0) {
				return sum[0];
			}
			else {
				return result;
			}

		}

		int[] sum_bak = sum.clone();
		result = serchSankosho(sankosho,sum,result,depth-1);

		sum = sum_bak;
		for(int i=0;i<input_M+1;i++) {
			sum[i] = sum[i] + sankosho[depth][i];
		}
		result = serchSankosho(sankosho,sum,result,depth-1);

		return result;
	}

}
