import java.util.Scanner;

public class Main {

	public static void main(String... nui) {
		Scanner sc = new Scanner(System.in);
		
		String s = sc.next();
		
		System.out.println((s.charAt(0) == '9' || s.charAt(1) == '9') ? "Yes" : "No");
		
	}

}
