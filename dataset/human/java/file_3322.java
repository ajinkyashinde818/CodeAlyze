import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner scan = new Scanner(System.in);
		String n = scan.next();

		if (n.indexOf("9") != -1) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}

}
