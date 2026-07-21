import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			char[] s = scanner.next().toCharArray();
			char[] t = scanner.next().toCharArray();

			Arrays.sort(s);
			Arrays.sort(t);

			String sString = new String(s);
			String tString = reverseString(t);

			System.out.println(sString.compareTo(tString) < 0 ? "Yes" : "No");
		}
	}

	private static String reverseString(char[] t) {
		return new StringBuffer(new String(t)).reverse().toString();
	}
}
