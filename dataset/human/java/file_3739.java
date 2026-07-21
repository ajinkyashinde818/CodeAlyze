import java.util.Scanner;

public class Main {

	public static void main(String args[]) {
		    Scanner sc = new Scanner(System.in);

		    String a = sc.next();
		    String b = sc.next();
		    int ai = Integer.parseInt(a.toLowerCase(),16);
		    int bi = Integer.parseInt(b.toLowerCase(),16);		    
		    if(ai > bi) {
		    	System.out.println(">");
		    }
		    else if(ai < bi){
		    	System.out.println("<");
		    }
		    else {
		    	System.out.println("=");
		    }
		    
		    sc.close(); }
}
