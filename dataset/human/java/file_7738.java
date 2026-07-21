//ループを発見する
import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		int town = scan.nextInt();
		long K = scan.nextLong();

		//  読み取り部分
		int[] warp = new int[town];
		int[] ahead = new int[town];
		for(int ct = 0; ct < town; ct++){
			warp[ct] = scan.nextInt();	
		}


		//　ループ部分導出準備
		int des = 0;
		int nums = 0;
		// ahead == 町を訪れた回数
		ahead[0] = 1;
		// times == 移動順記録　鳥の巣理論より町の数＋1回の移動時には少なくともループが発生している
		int[] times = new int[town + 1];
		times[0] = 0;
		// 移動を記録していく
		for(int ct = 0; ct < town; ct++){
			// ct度めの移動でどの町(配列順で考える→町番号－1)に向かうかを記録
			times[ct + 1] = warp[des] - 1;
			// 向かう町に行ったものとし訪れた回数に計上
			ahead[warp[des]-1]++;
			if(ahead[warp[des]-1] >= 2){
				// 移動回数を記録
				nums = ct + 1;
				break;
			}
			// 次の移動先を参照
			des = warp[des] - 1;
		}

		if(K > nums && nums != 0){
			for(int ct = 0; ct < town; ct++){
				if(times[ct] == warp[des]-1){
					K -= ct;
					nums -= ct;
					K %= nums;
					nums = ct;
					break;
				}
			}
			System.out.println(times[nums + (int)K] + 1);
		}else{
			System.out.println(times[(int)K] + 1);
		}

	}
}
