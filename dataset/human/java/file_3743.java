import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		char x=scan.next().charAt(0);
		char y=scan.next().charAt(0);
		if(x<y) {
			System.out.println("<");
		}
		else if(x>y) {
			System.out.println(">");
		}
		else {
			System.out.println("=");
		}

	}

}
