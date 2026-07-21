import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 参考書数
		int n = sc.nextInt();

		// 習得したいアルゴリズム数
		int m = sc.nextInt();

		// 習得目標理解度
		int x = sc.nextInt();

		// n番目の参考書の値段
		int[] costs = new int[n];

		// n番目の参考書のm番目のアルゴリズムの上昇理解度
		int[][] a = new int[n][m];

		// 入力の受け取り
		for (int i = 0; i < n; i++) {
			costs[i] = sc.nextInt();
			for (int j = 0; j < m; j++) {
				a[i][j] = sc.nextInt();
			}
		}

		// m番目のアルゴリズムの理解度、参考書コストのtmp変数と、loop毎の参考書コストを覚えておく変数、アルゴリズム習得達成したかの変数
		int[] aTmp = new int[m];
		int costTmp = 0;
		List<Integer> costsSave = new ArrayList<>();
		boolean mastered = true;

		/*
		 * ここからbit全探索
		 */
		for (int i = 0; i < 1 << n; i++) {
			// bit全探索の全通りのloop

			for (int j = 0; j < n; j++) {
				// 1loop毎にどの参考書を買うかの判定(j冊目を買うかどうか)

				if ((1 & i >> j) == 1) {
					// ここに引っかかった = 買う対象に追加(j冊目購入)

					for (int h = 0; h < m; h++) {
						// j冊目の参考書を買ったときのm番目のアルゴリズムの理解度上昇
						aTmp[h] += a[j][h];
					}

					// j冊目の値段
					costTmp += costs[j];

				}

			}

			// 参考書を買い終わったので、アルゴリズムを覚えられたかどうかの判定の上、値段を保持
			for (int h = 0; h < m; h++) {

				if (aTmp[h] < x) {
					// アルゴリズムを1つでも覚えられていない場合、NG
					mastered = false;
					break;
				}
			}

			if (mastered) {
				// 合計値段を一時格納
				costsSave.add(costTmp);
			}

			// 後始末
			for (int h = 0; h < m; h++) {
				aTmp[h] = 0;
			}
			costTmp = 0;
			mastered = true;

		}

		// listのうち最小の値を出力。リストがnullなら"-1"を出力
		int ans = Integer.MAX_VALUE;
		if (costsSave.isEmpty()) {
			ans = -1;
		} else {
			for (int cost : costsSave) {

				if (ans > cost) {
					ans = cost;
				}
			}
		}

		System.out.println(ans);

	}
}
