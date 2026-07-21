import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String[] alpha = {"A", "B", "C", "D", "E", "F"};
		String X = scan.next();
		String Y = scan.next();
		int XNum = 0;
		int YNum = 0;
		for(int i = 0; i < alpha.length; i++) {
			if(X.equals(alpha[i])) {
				XNum = i;
				break;
			}
		}
		for(int i = 0; i < alpha.length; i++) {
			if(Y.equals(alpha[i])) {
				YNum = i;
				break;
			}
		}
		if(XNum == YNum) {
			System.out.println("=");
		} else if(XNum > YNum) {
			System.out.println(">");
		} else if(XNum < YNum) {
			System.out.println("<");
		}
		scan.close();

	}

}
