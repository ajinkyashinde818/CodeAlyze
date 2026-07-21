import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String X = sc.next();
		String Y = sc.next();
		sc.close();
		if(X.charAt(0) > Y.charAt(0)) {
			System.out.println(">");
		}else if(X.charAt(0) == Y.charAt(0)) {
			System.out.println("=");
		}else {
			System.out.println("<");
		}
	}
}
