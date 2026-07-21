import java.util.Scanner;

public class Main {

	/*
	 *	...*....**
	 *	..........
	 *	**....**..
	 *	........*.
	 *	..*.......
	 *	..........
	 *	.*........
	 *	..........
	 *	....*..***
	 *	.*....*...
	 */

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while (true) {
			final int N = sc.nextInt();

			if (N == 0) {
				break;
			}

			boolean[][] is_wall = new boolean[N][N];

			for (int i = 0; i < N; i++) {
				char[] str = sc.next().toCharArray();

				for (int j = 0; j < N; j++) {
					is_wall[i][j] = str[j] == '*';
				}
			}

			int max = 0;
			
			int[][] dp = new int[N][N];
			for(int i = 0; i < N; i++){
				for(int j = 0; j < N; j++){
					if(is_wall[i][j]){
						dp[i][j] = 0;
						continue;
					}
					
					if(i == 0 && j == 0){
						dp[i][j] = 1;
					}else if(i == 0){
						dp[i][j] = 1;
					}else if(j == 0){
						dp[i][j] = 1;
					}else{
						if(!is_wall[i-1][j] && !is_wall[i][j-1] && !is_wall[i-1][j-1]){
							dp[i][j] = Math.min(Math.min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
						}else{
							dp[i][j] = 1;
						}
					}
					
					max = Math.max(max, dp[i][j]);
				}
			}
			
			
			System.out.println(max);

		}

	}

}
