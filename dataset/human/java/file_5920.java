import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		char a = s.charAt(0);
		char b = s.charAt(1);
		char c = s.charAt(2);
		boolean ans = true;

		if (a == b || a == c || b == c) {
			ans = false;
		}
		System.out.println(ans ? "Yes" : "No");
	}
}
