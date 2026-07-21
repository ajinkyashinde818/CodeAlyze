import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			int n = sc.nextInt();
			boolean bl = false;
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				int a = sc.nextInt();
				int b = sc.nextInt();
				if (a == b) {
					cnt++;
				} else {
					cnt = 0;
				}
				if (cnt >= 3) {
					bl = true;
				}
			}
			System.out.println(bl ? "Yes" : "No");
		}
	}
}
