import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = null;
		try {
			scanner = new Scanner(System.in);
			execute(scanner);
		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private static void execute(Scanner scanner) {
		String s = scanner.nextLine();
		System.out.println(s.substring(0, s.length() - "FESTIVAL".length()));
	}
}
