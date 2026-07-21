import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int x = scanner.nextInt();
		String result = "ARC";

		if (x < 1200) {
			result = "ABC";
		}
		System.out.println(result);
	}

}
