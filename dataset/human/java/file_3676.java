import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String X = scanner.next();
		String Y = scanner.next();

		if(X.charAt(0)<Y.charAt(0)) {
			System.out.println("<");
		}else if(X.charAt(0)==Y.charAt(0)){
			System.out.println("=");
		}else{
			System.out.println(">");
		}
	}
}
