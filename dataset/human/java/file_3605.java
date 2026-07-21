import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			String X = sc.next();
			String Y = sc.next();
			
			int a = X.compareTo(Y);
			if(a > 0) System.out.println(">");
			if(a == 0) System.out.println("=");
			if(a < 0) System.out.println("<");
		}
	}
}
