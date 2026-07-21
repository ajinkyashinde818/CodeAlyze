import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		boolean test = false;

		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();
		int[] c = new int[n];
		int[][] a = new int[n][m];
		int[] srtc = new int[n];
		int[][] srta = new int[n][m];
		long res = -1;

		int[] a_ideal = new int[m]; //各理解度の理論合計値
		for(int jj = 0; jj < m; jj++) {
			a_ideal[jj] = 0;
		}


		for(int i = 0; i < n; i++) {
			c[i] = sc.nextInt();
			for(int jj = 0; jj < m; jj++) {
				a[i][jj] = sc.nextInt();
				a_ideal[jj] += a[i][jj];
			}
		}

		if(test){//print
			System.out.printf("%d %d %d\n", n,m,x);
			for(int i = 0; i < n; i++) {
				System.out.printf("%d", c[i]);
				for(int jj = 0; jj < m; jj++) {
					System.out.printf(" %d", a[i][jj]);
				}
				System.out.println();
			}
			System.out.printf("total: ");
			for(int jj = 0; jj < m; jj++) {
				System.out.printf(" %d", a_ideal[jj]);
			}
			System.out.println();
		}

		//すべての参考書を購入しても理解度が足りないアルゴリズムがあれば終了
		for(int jj = 0; jj < m; jj++) {
			if(a_ideal[jj] < x) {
				System.out.printf("-1");
				return;
			}
		}

		//ソート
		//まず値段をソート
		System.arraycopy(c, 0, srtc, 0, n);
		Arrays.sort(srtc);
		if(test){//print
		}
		//テーブルをソート
		for(int i = 0; i < n; i++) {
			for(int jj = 0; jj < n; jj++) {
				if(srtc[i] == c[jj]) {
					System.arraycopy(a[jj], 0, srta[i], 0, m);
					//重複防止
					c[jj] = 0;
					break;
				}
			}
		}
		if(test){//print
			System.out.println();
			for(int i = 0; i < n; i++) {
				System.out.printf("%d", srtc[i]);
				for(int jj = 0; jj < m; jj++) {
					System.out.printf(" %d", srta[i][jj]);
				}
				System.out.println();
			}
		}


		//総当たり?
		boolean setting[] = new boolean[n];
		int pattern = (int)Math.pow(2, n);
		long currentRes;
		for(int i=0; i<pattern; i++) {
			int tmp = i;
			for(int jj=0; jj<n; jj++) {
				if(tmp%2 == 1) setting[jj] = true;
				else setting[jj] = false;
				tmp /= 2;
			}
			currentRes = createAndJudgeAndCulcPrice(setting, srtc, srta, m, n, x);
			if(test) System.out.printf("%d/%d %d %d\n", i, pattern, currentRes, res);

			if((res == -1 && currentRes != -1) ||
					(res != -1 && currentRes != -1 && currentRes < res)){
				res = currentRes;
			}
		}
		System.out.printf("%d", res);

	}

	private static long createAndJudgeAndCulcPrice(boolean[] setting, int price[], int table[][], int m, int n, int x) {
		int skill[] = new int[m];
		for(int i = 0; i < m; i++) {
			skill[i] = 0;
		}

		long totalPrice = 0;
		for(int i = 0; i < n; i++) {
			if (setting[i]) {
				totalPrice += price[i];
				for(int jj = 0; jj < m; jj++) {
					skill[jj] += table[i][jj];
				}
			}
		}
		if(judge(skill, m, x)) {
			return totalPrice;
		} else {
			return -1;
		}
	}

	private static boolean judge(int[] skill, int count, int require) {
		for(int idx = 0; idx < count; idx++) {
			if(skill[idx] < require) return false;
		}
		return true;
	}
}
