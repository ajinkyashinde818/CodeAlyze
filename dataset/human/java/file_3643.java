import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char c = sc.next().toCharArray()[0];
		char c2 = sc.next().toCharArray()[0];
		if(c > c2) {
			System.out.println(">");
		} else if(c == c2) {
			System.out.println("=");
		} else {
			System.out.println("<");
		}
	}
}
