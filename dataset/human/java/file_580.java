import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			new Main().exec(sc);
		}
	}

	public void exec(Scanner sc) {
		int n = sc.nextInt();
		int r = sc.nextInt();
		int rating = 0;
		if (n >= 10) {
			rating = r;
		} else {
			rating = r + (100 * (10 - n));
		}
		System.out.println(rating);
	}
}
