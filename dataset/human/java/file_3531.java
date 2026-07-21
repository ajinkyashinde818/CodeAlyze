import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner scan = new Scanner(System.in);
		String x = scan.next();
		String y = scan.next();

		if (x.compareTo(y) > 0) {
			System.out.println(">");
		} else if (x.compareTo(y) < 0) {
			System.out.println("<");
		} else {
			System.out.println("=");
		}
	}

}
