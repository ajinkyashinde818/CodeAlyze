import java.util.Arrays;
import java.util.Scanner;

// https://atcoder.jp/contests/abc167/tasks/abc167_c
public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();

		int[] c = new int[n];
		int[][] array = new int[n][m];
		for (int i = 0; i < n; i++) {
			c[i] = sc.nextInt();
			for (int j = 0; j < m; j++) {
				array[i][j] = sc.nextInt();
			}
		}
		sc.close();


		int ans = Integer.MAX_VALUE;

		for (int p=0; p<(Math.pow(2,n)); p++) {
			int cost = 0;
			int[] arrayX = new int[m];
			Arrays.fill(arrayX, 0);

			for(int i=0;i<n;i++) {
				if((1 & (p >> i)) == 1){
					cost = cost + c[i];
					for(int j=0;j<m;j++) {
						arrayX[j] = arrayX[j] + array[i][j];
					}
				}
			}

			boolean flag = true;
			for(int i=0;i<m;i++) {
				if(arrayX[i]<x) {
					flag = false;
					break;
				}
			}

			if(flag) {
				ans = Math.min(ans, cost);
			}
		}

		if(ans==Integer.MAX_VALUE) {
			System.out.println(-1);
		}else {
			System.out.println(ans);
		}
	}
}
