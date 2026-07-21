import java.util.Scanner;

/**
 * お遊び
 *
 * @author s-sugimoto
 */
public class Main {

	/**
	 * 隠蔽
	 */
	private Main() {
	}

	/**
	 * main
	 *
	 * @param args 起動引数
	 */
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Integer num1 = scanner.nextInt();

		if (num1.toString().contains("9")) {
			System.out.println("Yes");

		} else {
			System.out.println("No");
		}
	}
}
