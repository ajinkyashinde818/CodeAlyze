import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int k, s, ans = 0;
		k = sc.nextInt();
		s = sc.nextInt();
		sc.close();

		for (int i = 0; i <= k; ++i) {
			for (int j = 0; j <= k; ++j) {
				int tmp = s - i - j;
				if (tmp >= 0 && tmp <= k)
					ans++;
			}
		}
		System.out.println(ans);
	}

}
