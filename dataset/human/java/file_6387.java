import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int s = sc.nextInt();
		sc.close();

		int ans = 0;
		for (int i = 0; i <= k; i++) {
			for (int j = 0; j <= k; j++) {
				if (i + j <= s && s <= i + j + k) {
					ans++;
				}
			}
		}
		System.out.println(ans);
	}
}
