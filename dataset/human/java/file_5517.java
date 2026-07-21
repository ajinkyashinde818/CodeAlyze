import java.util.Scanner;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		String ans = "";

		if (n < 1200) {
			ans = "ABC";
		} else {
			ans = "ARC";
		}

		System.out.println(ans);
	}
}
