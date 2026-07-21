import java.util.Scanner;

public class Main {
	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);

		// 整数の入力
		int a = sc.nextInt();
		int zoro_cnt = 0;

		for (int i = 0; i < a; i++) {
			int b = sc.nextInt();
			int c = sc.nextInt();
			if (b == c) {
				zoro_cnt++;
				if (zoro_cnt >= 3) {
					break;
				}
			} else {
				zoro_cnt = 0;
			}
		}

		if (zoro_cnt >= 3) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
