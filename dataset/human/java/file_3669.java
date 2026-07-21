import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			String X = sc.next();
			String Y = sc.next();

			if(X.charAt(0) < Y.charAt(0)){
				System.out.println("<");
			} else if(X.charAt(0) > Y.charAt(0)){
				System.out.println(">");
			} else {
				System.out.println("=");
			}
		}
	}
}
