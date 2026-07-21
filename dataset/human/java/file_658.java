import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力値の取得
		int N = sc.nextInt();
		int R = sc.nextInt();
		
		// 結果の出力
		if (N < 10) {
			System.out.println(100*(10-N)+R);
		}
		else {
			System.out.println(R);
		}

		sc.close();
	}
}
