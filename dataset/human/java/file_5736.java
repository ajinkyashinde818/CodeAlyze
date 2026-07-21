import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		
		String s = stdIn.next();
		
		if ((s.contains("a")) && (s.contains("b")) && (s.contains("c"))) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
