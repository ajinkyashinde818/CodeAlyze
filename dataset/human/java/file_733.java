import java.util.Scanner;

public class Main {
	static String s = "";

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int R = sc.nextInt();

		int ans = R;
		if(N < 10) {
			ans = R + 100 * (10 - N);
		}

		System.out.println(ans);
	}

}
