import java.util.Scanner;

public final class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int n = scanner.nextInt();
			int r = scanner.nextInt();

			if (n >= 10 ) {
				System.out.println(r);
			} else {
				System.out.println(r + 100 * (10 - n));
			}
		}
	}

}
