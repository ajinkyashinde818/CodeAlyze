import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		String S = sc.next();

		if (S.substring(0, 1).equals("a") &&
				S.substring(1, 2).equals("b") &&
				S.substring(2, 3).equals("c")) {
			System.out.println("Yes");
		}else if (S.substring(0, 1).equals("a") &&
				S.substring(1, 2).equals("c") &&
				S.substring(2, 3).equals("b")) {
			System.out.println("Yes");
		}else if (S.substring(0, 1).equals("b") &&
				S.substring(1, 2).equals("c") &&
				S.substring(2, 3).equals("a")) {
			System.out.println("Yes");
		}else if (S.substring(0, 1).equals("b") &&
				S.substring(1, 2).equals("a") &&
				S.substring(2, 3).equals("c")) {
			System.out.println("Yes");
		}else if (S.substring(0, 1).equals("c") &&
				S.substring(1, 2).equals("b") &&
				S.substring(2, 3).equals("a")) {
			System.out.println("Yes");
		}else if (S.substring(0, 1).equals("c") &&
				S.substring(1, 2).equals("a") &&
				S.substring(2, 3).equals("b")) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}

	}
}
