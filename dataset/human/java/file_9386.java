import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			int n = sc.nextInt();
			int max = 0;
			int cnt = 0;

			for (int i = 0; i < n; i++) {
				if (sc.nextInt() == sc.nextInt()) {
					cnt++;
				} else {
					cnt = 0;
				}
				if (max < cnt) {
					max = cnt;
				}
			}
			if (max >= 3) {
				System.out.println("Yes");
			} else {
				System.out.println("No");
			}
		}
	}
}
