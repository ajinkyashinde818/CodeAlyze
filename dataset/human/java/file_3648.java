import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String X = sc.next();
		String Y = sc.next();
		char x = X.toCharArray()[0];
		char y = Y.toCharArray()[0];
		if (x < y) System.out.println("<");
		else if (y < x) System.out.println(">");
		else System.out.println("=");
	}
}
