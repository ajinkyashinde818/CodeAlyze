import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x = sc.next();
		String y = sc.next();
		char xc = x.charAt(0);
		char yc = y.charAt(0);

		if(xc > yc) {
			System.out.println(">");
		}else if(xc == yc) {
			System.out.println("=");
		}else {
			System.out.println("<");
		}
	}

}
