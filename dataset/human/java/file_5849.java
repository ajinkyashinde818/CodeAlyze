import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner stdin = new Scanner(System.in);
		String s= stdin.next();
		if(s.contains("a")&&s.contains("b")&&s.contains("c")) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}

	}

}
