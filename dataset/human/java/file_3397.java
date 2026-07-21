import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int n2 = n / 10;
		int n1 = n % 10;
		String message = "No";
		if(n1 == 9 || n2 == 9) {
			message = "Yes";
		}
		System.out.println(message);
	}
}
