import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x = sc.next();
		String y = sc.next();

		int comp = x.compareTo(y);

		if (comp < 0) {
			System.out.println("<");
		} else if (comp == 0) {
			System.out.println("=");
		} else {
			System.out.println(">");
		}

		sc.close();
	}
}
