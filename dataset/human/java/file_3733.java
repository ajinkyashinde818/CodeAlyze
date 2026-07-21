import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String X = sc.next();
		String Y = sc.next();
		String ans = " ";

		if ( X.compareTo(Y) < 0 ) {
			ans = "<";
		} else if ( X.compareTo(Y) > 0 ) {
			ans = ">";
		} else {
			ans = "=";
		}

		System.out.println( ans );
	}
}
