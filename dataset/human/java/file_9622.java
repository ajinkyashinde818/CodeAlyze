import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		//入力値取得
		int N = scan.nextInt();

		int[] D = new int[2 * N];

		for (int i = 0; i < 2 * N; i += 2) {
			D[i] = scan.nextInt();
			D[i + 1] = scan.nextInt();
		}
		String ans = "No";

		for (int i = 0; i < 2 * (N - 2); i += 2) {
			if (D[i] == D[i + 1] && D[i + 2] == D[i + 3] && D[i + 4] == D[i + 5]) {
				ans = "Yes";
			}
		}

		//結果出力
		System.out.println(ans);
	}
}
