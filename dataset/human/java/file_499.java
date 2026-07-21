import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ

		Scanner scanner = new Scanner(System.in);

		//入力表示
		int N = scanner.nextInt();
		int R = scanner.nextInt();
		
      //10以上はそのまま表示、10以下は計算して表示
		if (N >= 10) {
			System.out.println(R);
		} else {
			System.out.println(R + 100 * (10 - N));
		}
		scanner.close();
	}
}
