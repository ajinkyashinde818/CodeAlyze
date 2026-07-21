import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			execute(scanner);
		}
	}

	private static void execute(Scanner scanner) {
		String[] array = scanner.nextLine().split(" ");
		int x = array[0].charAt(0);
		int y = array[1].charAt(0);
		if (x < y) {
			System.out.println("<");
			return;
		}
		if (x > y) {
			System.out.println(">");
			return;
		}
		System.out.println("=");
	}
}
