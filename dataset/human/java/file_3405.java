import java.util.Scanner;
public class Main {
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);

		String N = null;
		int result = 0;

		N = sc.next();
		result = N.indexOf("9");

		if(result != -1) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}
}
