import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 文字列の入力
		String x = sc.next();
		String y = sc.next();

		String ans = "";

		if(x.compareTo(y) < 0){
			ans = "<";
		}else if (x.compareTo(y) == 0){
			ans = "=";
		}else{
			ans = ">";
		}
		// 出力
		System.out.println(ans);
	}
}
