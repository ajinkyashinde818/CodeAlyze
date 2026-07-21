import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String s = sc.nextLine();

		boolean a = false;
		boolean b = false;
		boolean c = false;

		if (s.contains("a")) {
			a = true;
		}
		if (s.contains("b")) {
			b = true;
		}
		if (s.contains("c")) {
			c = true;
		}

		if (a && b && c) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
		sc.close();

	}
}
