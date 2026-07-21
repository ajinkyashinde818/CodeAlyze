import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		String X = scan.next();
		char x = X.charAt(0);
	
		String Y = scan.next();
		char y = Y.charAt(0);
		if(x>y){
			System.out.println(">");
		}else if(x == y){
			System.out.println("=");
		}else{
			System.out.println("<");
		}
		
	}

}
