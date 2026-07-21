import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String N = scanner.next();
		String result = "No";

		for (int i = 0; i < 2; i++) {
			if (N.substring(i, i+1).equals("9")) {
				result = "Yes";
			}

		}
		System.out.println(result);
	}

}
