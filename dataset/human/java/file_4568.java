import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int ans = 0;
		if (c <= b) {
			ans += c + b;
		} else {
			ans += 2 * b;
			c -= b;
			b = 0;
			ans += Math.min(c, a);
			c -= Math.min(c, a);
			if (c > 0) {
				ans++;
			}
		}
		System.out.println(ans);
	}
}
