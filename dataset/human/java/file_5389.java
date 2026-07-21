import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner scan = new Scanner(System.in);
		if (1200 > scan.nextInt()) {
			System.out.println("ABC");
		} else {
			System.out.println("ARC");
		}

	}

}
