import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		
		int a = stdIn.nextInt();
		
		if (a >= 1200) {
			System.out.println("ARC");
		} else {
			System.out.println("ABC");
		}
	}
}
