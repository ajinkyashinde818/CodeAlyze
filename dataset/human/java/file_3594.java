import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = Integer.parseInt(sc.next(),16);
		int y = Integer.parseInt(sc.next(),16);
		sc.close();
	
	if (x < y) 
		System.out.println("<");
	 else if (x == y) 
		 System.out.println("=");
	 else 
		 System.out.println(">");
	
	}
}
