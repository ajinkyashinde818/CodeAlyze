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
		int count = 0;
		for (StringBuilder stringBuilder = new StringBuilder(s); stringBuilder.length() > 1;) {
			int end = stringBuilder.length() - 1;
			if (stringBuilder.charAt(0) == stringBuilder.charAt(end)) {
				stringBuilder.deleteCharAt(end).deleteCharAt(0);
				continue;
			}
			if (stringBuilder.charAt(0) == 'x') {
				stringBuilder.deleteCharAt(0);
				count++;
				continue;
			}
			if (stringBuilder.charAt(end) == 'x') {
				stringBuilder.deleteCharAt(end);
				count++;
				continue;
			}
			count = -1;
			break;
		}
		System.out.println(count);
	}
}
