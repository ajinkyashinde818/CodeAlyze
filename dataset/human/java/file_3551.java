import java.util.Scanner;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		String  x = scanner.next();
		String y=scanner.next();

		if(x.charAt(0)<y.charAt(0)) {
			System.out.println("<");
		}else if(x.charAt(0)>y.charAt(0)) {
			System.out.println(">");
		}else {
			System.out.println("=");
		}
	}
}
