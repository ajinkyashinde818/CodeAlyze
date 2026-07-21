import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		char a= scan.next().charAt(0);
		char b = scan.next().charAt(0);
		if((int)a<(int)b) System.out.println("<");
		else if((int)a>(int)b) System.out.println(">");
		else System.out.println("=");

	}

}
