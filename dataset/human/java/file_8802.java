import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();

		int cnt = 0;
		int ans = 100;

		while (true) {
			if (a % ans == 0 && b % ans == 0) {
				cnt++;
			}
			if (cnt == k) {
				break;
			}
			ans--;
			if (ans < 0) {
				break;
			}
		}

		System.out.println(ans);

		sc.close();
	}
}
