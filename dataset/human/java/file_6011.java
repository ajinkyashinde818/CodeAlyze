import java.util.Scanner;

public class Main {
	  
	public static void main(String args[]) {
		    Scanner scanner = new Scanner(System.in);
		    
		    String s = scanner.nextLine();
		    if( s.indexOf("a") != -1 && s.indexOf("b") != -1 
		    		&& s.indexOf("c")!= -1 )
		    {
		    	System.out.println("Yes");
		    }
		    else 
		    {
		    	System.out.println("No");
		    }
		    
		    scanner.close(); }
		  }
