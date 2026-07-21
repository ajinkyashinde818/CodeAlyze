import java.util.*;

class Main{
	public static void main(String[] args){
		//入力準備
		Scanner sc = new Scanner(System.in);

		//参加回数と表示レーティングの入力
		int N = sc.nextInt();
		int R = sc.nextInt();
	
		//内部レーティングXの定義
		int X = 0;

		if(N >= 10){
			X = R;
		}else{
			X = R + 100 * (10 - N);
		}

		System.out.println(X);
	}
}
