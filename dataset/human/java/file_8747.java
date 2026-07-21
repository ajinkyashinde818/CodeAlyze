import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();

		int c = Math.min(a, b);
		int cnt = 0;
		int ans = 0;
		for (int i = c; i > 0; i--) {
			if (a % i == 0 && b % i == 0) {
				cnt++;
				if (cnt == k) {
					ans = i;
					break;
				}
			} else {
				continue;
			}
		}
		System.out.println(ans);
	}

}
