import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int hon = scan.nextInt();
		int arugo = scan.nextInt();
		int min = scan.nextInt();
		int[] nedan = new int[hon];
		int[][] array = new int[hon][arugo];

		boolean flg = false;

		for(int i=0;i<hon;i++) {
			 nedan[i] = scan.nextInt();
			for(int j=0;j<arugo;j++) {
				array[i][j] = scan.nextInt();

			}
		}

		int[] aTmp = new int[arugo];
		int costTmp = 0;
		List<Integer> costSave = new ArrayList<>();

		//bit探索の全通り
		for(int i=0;i< 1<<hon ;i++) {
			//１ループ毎にどの参考書を買うかの判定
			for(int j=0;j<hon;j++) {
				//ここに引っかかる = 買う対象に追加（j冊目購入）
				if((1 & i >> j) == 1) {
					for(int h=0;h<arugo;h++) {

					//j冊目の参考書を買ったときのarugo番目のアルゴリズムの理解度上昇
						aTmp[h] += array[j][h];
				}
					//j冊目の値段
					costTmp += nedan[j];
				}
			}

			//参考書を買い終わったのでアルゴリズムを覚えたかの判定の上、値段を保持

			for(int h =0;h<arugo;h++) {
				if(aTmp[h] < min) {
					//アルゴリズム一つも覚えてない
					flg = false;
					break;
				}
			}

			if(flg) {
				//合計値段を一時格納
				costSave.add(costTmp);
			}

			//後始末
			for(int h=0;h<arugo;h++) {
				aTmp[h]=0;
			}
			costTmp = 0;
			flg = true;

		}

		//listのうち最小の値を出力、リストがnullなら-1を出力
		int re = Integer.MAX_VALUE;
		if(costSave.isEmpty()) {
			re = -1;
		}else {
			for(int cost:costSave) {
				if(re > cost) {
					re = cost;
				}
			}
		}

		System.out.println(re);

		scan.close();

	}

}
