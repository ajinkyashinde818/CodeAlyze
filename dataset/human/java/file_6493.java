import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		try {
			int k = sc.nextInt();
			int s = sc.nextInt();

			int ans = 0;
			for (int a = 0; a <= k; a++) {
				if (a == s) {
					ans++;
					break;
				}
				int bc  = (int) Math.ceil((double) (s - a) / 2);
				if (bc <= k) {
					for (int b = 0; b <= k; b++) {
						if (s - a - b >= 0 && s - a - b <= k) {
							ans++;
						}
					}
				}
			}

			System.out.println(ans);

		} finally {
			sc.close();
		}
	}
}
