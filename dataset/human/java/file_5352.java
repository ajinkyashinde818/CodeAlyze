import java.util.*;

class Main{
	public static void main(String[] $){
		//入力
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		sc.close();

		//処理
		String ans = "ABC";
		if(x >= 1200) ans = "ARC";

		//出力
		System.out.println(ans);
	}
}
