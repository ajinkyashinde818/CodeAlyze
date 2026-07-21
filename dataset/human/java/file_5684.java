import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int k = scanner.nextInt();

		int s = scanner.nextInt();
		int t = s < 3 ? s + 1 : s - 1;

		for (int i = 0; i < n; i++) {
			System.out.print(i < k ? s : t);
			System.out.print(i == n - 1 ? "\n" : " ");
		}

	}

}
