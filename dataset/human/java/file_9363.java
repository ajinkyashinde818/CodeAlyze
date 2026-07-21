import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		int max = 0;
		boolean can = false;
		for (int i = 0; i < n; i++) {
			int d = sc.nextInt();
			int e = sc.nextInt();
			if (d == e) {
				max++;
			} else {
				max = 0;
			}
			if (max == 3) can = true;
		}

		if (can) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}

		sc.close();

	}
}
