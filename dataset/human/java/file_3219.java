import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String s = scan.next();
		scan.close();
		if(Character.getNumericValue(s.charAt(0))==9 ||
				Character.getNumericValue(s.charAt(1))==9)System.out.println("Yes");
		else System.out.println("No");

	}

}
