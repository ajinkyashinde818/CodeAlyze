import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int k = sc.nextInt(), s = sc.nextInt();
		int ans = 0;
		for (int i = 0; i <= k; i++) {
			for (int j = 0; j <= k; j++) {
				int tmp = s - (i + j);
				if (0 <= tmp && tmp <= k) {
					ans++;
				}
			}
		}
		System.out.println(ans);
	}
}
