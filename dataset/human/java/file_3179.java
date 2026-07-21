import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		
		String a = stdIn.next();
		
		if (a.contains("9")) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
