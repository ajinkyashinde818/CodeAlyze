import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner scan = new Scanner(System.in);
		String s = scan.next();
		if (s.contains("a") && s.contains("b") && s.contains("c")) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}

}
