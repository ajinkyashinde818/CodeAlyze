import java.util.Scanner;

public class Main {
	static public void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String s = scan.next();
		scan.close();

		if (s.contains("a") && s.contains("b") && s.contains("c")) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
