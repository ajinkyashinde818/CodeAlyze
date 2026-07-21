import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.nextLine().trim();
		if (S.contains("a") && S.contains("b") && S.contains("c")) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
