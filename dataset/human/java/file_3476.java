import java.util.Scanner;
 
public class Main {
 
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String a = scanner.next();
		String b = scanner.next();
		
		int c = Integer.parseInt(a, 16);
		int d = Integer.parseInt(b, 16);
		
		if (c>d) {
			System.out.println(">");
		}else if (c==d) {
			System.out.println("=");
		}else{
			System.out.println("<");
		}
		
		scanner.close();
	}
	
}
