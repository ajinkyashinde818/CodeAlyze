import java.util.Scanner;

public class Main{
	//X+Y+Z=S （ただし、X,Y,ZはK以下の数字）で何パターンあるか？？？
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str0 = sc.nextLine();
		String[] array0 = str0.split(" ");
		int K = Integer.parseInt(array0[0]);//合計値
		int S = Integer.parseInt(array0[1]);//最大値
		int result=0;

		for(int x=0;x <= K;x++){//Xの値パターン

			 for(int y=0;y <= K;y++){//Yの値パターン

				 if(0 <= S-x-y && S-x-y <= K){
					 // Z = S(合計)-X-Y で0以上かつ、K以下ならばカウントする
					 result++;
				 }
			 }
		}
		System.out.println(result);
	}

}
