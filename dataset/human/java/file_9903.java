import java.util.Arrays;
import java.util.Scanner;
public class Main{
	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String[] tmp = scanner.nextLine().split(" ");
		int n       = Integer.parseInt(tmp[0]);
		int m       = Integer.parseInt(tmp[1]);
		int x       = Integer.parseInt(tmp[2]);

		int[][] cst = new int[n][m + 1];
		for(int i = 0; i < cst.length; i++) {
			String[] temp = scanner.nextLine().split(" ");

			for(int j = 0; j < temp.length; j++) {
				cst[i][j] = Integer.parseInt(temp[j]);
			}
		}

		int[] lst   = new int[m];
		Arrays.fill(lst, 0);
		boolean flg = true;
		int ans     = Integer.MAX_VALUE;
		int amo     = 0;

		for(int i = 0; i < 1 << n;i++) {

			//lstへの数値入力
			for(int j = 0; j < cst.length; j++) {
				if(((i >> j) & 1) == 1) {
					amo += cst[j][0];

					for(int k = 0; k < m; k++) {
						lst[k] += cst[j][k+1];
					}
				}
			}

			//x以上か判定
			for(int a : lst) {
				if(a < x) {
					flg = false;
					break;
				}
			}

			//最小か判定
			ans = flg ? Math.min(ans, amo) : ans;

			flg = true;
			amo = 0;
			Arrays.fill(lst, 0);
		}

		if(ans == Integer.MAX_VALUE) {
			System.out.println(-1);
		}else {
			System.out.println(ans);
		}

	}
}
