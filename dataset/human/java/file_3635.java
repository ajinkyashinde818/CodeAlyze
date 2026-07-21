import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String s1 = scan.next();
		String s2 = scan.next();
		char c1 = s1.charAt(0);
		char c2 = s2.charAt(0);
		if (c1==c2) {
			System.out.println("=");
		}
		if (c1>c2) {
			System.out.println(">");
		}
		if (c1<c2) {
			System.out.println("<");
		}
	}
}
