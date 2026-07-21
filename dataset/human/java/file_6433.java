import java.util.Scanner;

/**
 * TITLE : Sum of Three Integers
 * URL : https://atcoder.jp/contests/abc051/tasks/abc051_b
 */
public class Main {

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int s = sc.nextInt();

		int count = 0;
		for (int x = 0; x <= k; x++) {
			for (int y = 0; y <= k; y++) {
				int temp = s - x - y;
				if (temp >= 0 && temp <= k) count++;
			}
		}
		System.out.println(count);
		sc.close();
	}
}
