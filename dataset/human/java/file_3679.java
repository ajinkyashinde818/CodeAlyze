import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		char x = stdIn.next().charAt(0);
		char y = stdIn.next().charAt(0);
		
		if(x-y <0) {
			System.out.println("<");
		}else if(x-y >0) {
			System.out.println(">");
		}else {
			System.out.println("=");
		}
		
		
		
	}

}
