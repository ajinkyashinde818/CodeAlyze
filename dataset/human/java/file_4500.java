import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try {
			Scanner scanner = new Scanner(System.in);

			int a = scanner.nextInt();
			int b = scanner.nextInt();
			int c = scanner.nextInt();

			int answer = 0;

			if ((a + b) == c) {
				answer = c + b;
			} else if ((a + b) < c) {
				answer = a + b + 1 + b;
			} else {
				answer = b + c;
			}

			System.out.println(answer);

			scanner.close();
		} catch (InputMismatchException e) {
			System.out.println("整数を入力してください。");
		}
	}

}
