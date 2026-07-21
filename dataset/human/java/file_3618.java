import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String hex1 = scanner.next();
		String hex2 = scanner.next();
		
		int num1 = Integer.parseInt(hex1, 16);
		int num2 = Integer.parseInt(hex2, 16);
		
		if (num1>num2) {
			System.out.println(">");
		}else if (num1==num2) {
			System.out.println("=");
		}else{
			System.out.println("<");
		}
		
		scanner.close();
	}
	
}
