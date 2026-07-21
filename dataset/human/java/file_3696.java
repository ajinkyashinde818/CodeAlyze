import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int X = (int)sc.next().charAt(0);
		int Y = (int)sc.next().charAt(0);
		sc.close();
		
		if(X == Y)
			System.out.println("=");
		else if(X < Y)
			System.out.println("<");
		else
			System.out.println(">");
	}
}
