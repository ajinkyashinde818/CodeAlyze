import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// 入力1をnに入れる
		int k = sc.nextInt();
		int s = sc.nextInt();
		int count = 0;
		int l;

		for (int i = 0; i <= k; i++) {
			for (int j = 0; j <= k; j++) {
				l = s - i - j;
				if ( !(l < 0 || k < l) && i + j + l == s) {
					count++;
				}
			}
		}

		System.out.println(count);
	}
}
