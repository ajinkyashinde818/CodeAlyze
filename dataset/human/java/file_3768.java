import java.util.Scanner;

public class Main{
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		String X = scan.next();
		String Y = scan.next();
		int intX = Character.getNumericValue(X.charAt(0));
		int intY = Character.getNumericValue(Y.charAt(0));
		if (intX < intY) {
			System.out.println("<");
		} else if (intX > intY){
			System.out.println(">");
		} else {
			System.out.println("=");
		}
	}
}
