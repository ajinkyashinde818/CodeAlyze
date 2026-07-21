import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String S = sc.next();
		String ans = "";

		if ( S.contains("a") && S.contains("b") && S.contains("c") ) {
			ans = "Yes";
		} else {
			ans = "No";
		}

		System.out.println( ans );
	}
}
