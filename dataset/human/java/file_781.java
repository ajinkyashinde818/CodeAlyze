import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		int[] input = new int[2];
		for (int i = 0; i < 2; i++) {
			input[i] = sc.nextInt();
		}
		// 参加回数:N
		int n = input[0];
		// 表示レーティング:R
		int r = input[1];
		// 内部レーティング:output
		int output;
		
		// 参加回数が10回未満の場合
		if (n < 10) {
			output = r + 100 * (10 -n);
			
		// 参加回数が10回以上の場合
		} else {
			output = r;
		}
		
		System.out.println(output);

	}

}
