import java.util.*;


public class Main{
	public static void main( String args[] ) {

		int counter  = 0;
		int a;
		int b;
		int c;
		
		boolean isDoku;
		
		Scanner scan = new Scanner( System.in );
		a = scan.nextInt();
		b = scan.nextInt();
		c = scan.nextInt();
		
		counter = 0;
		isDoku = true;
		
		
		if( a + b >= c ) {
			counter = c + b;
		}
		else {
			counter = b + a + b + 1;
		}
		
		
		System.out.println( counter );
		
		scan.close();
		
	}
}
