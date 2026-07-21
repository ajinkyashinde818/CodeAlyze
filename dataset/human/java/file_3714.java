import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		String X = s.next();
		String Y = s.next();


		String ans=(int)X.charAt(0)<(int)Y.charAt(0)?"<"
				:(int)X.charAt(0)==(int)Y.charAt(0)?"=":">";

		System.out.println(ans);
	}
}
