import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner((System.in));
		String N = sc.next();

			if (N.contains("9")) {
				System.out.println("Yes");
				sc.close();
				return;
			}
		
		System.out.println("No");

		sc.close();
	}
}
