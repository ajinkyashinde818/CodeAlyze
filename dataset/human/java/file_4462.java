import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(System.in);
		int a = scanner.nextInt();
		int b = scanner.nextInt();
		int c = scanner.nextInt();
		int safe = a + b;
		if (c <= safe) {
			System.out.println(b + c);
			return;
		}
		System.out.println(safe + 1 + b);
	}
}
