import java.util.*;
public class Main{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		
		char a = sc.next().charAt(0), b = sc.next().charAt(0);
		if(a > b) System.out.println(">");
		if(a < b) System.out.println("<");
		if(a == b) System.out.println("=");
	}

}
