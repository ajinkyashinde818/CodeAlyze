import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String s = scan.next();
		char x=s.charAt(0);
		s=scan.next();
		char y=s.charAt(0);
		scan.close();
		if(x>y)System.out.println(">");
		else if(x<y)System.out.println("<");
		else System.out.println("=");

	}

}
