import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			String line = scanner.nextLine();
			if (line.indexOf('a') >= 0 && line.indexOf('b') >= 0 && line.indexOf('c') >= 0) {
				System.out.println("Yes");
			} else {
				System.out.println("No");
			}
		}
	}
}
