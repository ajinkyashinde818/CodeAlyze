import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		
		String a = stdIn.next();
		String b = stdIn.next();
		
		if (a.charAt(0) > b.charAt(0)) {
			System.out.println(">");
		} else if (a.charAt(0) < b.charAt(0)) {
			System.out.println("<");
		} else {
			System.out.println("=");
		}
	}
}
