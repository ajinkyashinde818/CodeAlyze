import java.util.Scanner;

public class Main {
	  
	public static void main(String args[]) {
		    Scanner scanner = new Scanner(System.in);
		    
		    String N = scanner.nextLine();
		    
		    if( N.indexOf("9") == -1 ) 
		    {
		    	System.out.println("No");
		    }
		    else 
		    {
		    	System.out.println("Yes");
		    }
		    
		    scanner.close(); }
		  }
