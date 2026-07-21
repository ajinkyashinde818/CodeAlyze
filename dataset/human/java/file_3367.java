import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String N = scan.next();
		if(N.substring(0, 1).equals("9") || N.substring(1, 2).equals("9")) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
		scan.close();
	}

}
