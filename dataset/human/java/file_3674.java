import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char a = sc.next().toCharArray()[0];
		char b= sc.next().toCharArray()[0];


		if (a < b) {
			System.out.println("<");
		} else if (b < a) {
			System.out.println(">");
		} else {
			System.out.println("=");
		}

		sc.close();

	}

}
