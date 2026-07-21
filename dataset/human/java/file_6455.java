import java.util.Scanner;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int k = scanner.nextInt();
		int s = scanner.nextInt();

		int ans = 0;
		for (int x = 0; x <= k; x++) {
			for (int y = 0; y <= k; y++) {
				if (0 <= s - x - y && s - x - y <= k) {
					ans++;
				}
			}
		}

		System.out.println(ans);
	}
}
