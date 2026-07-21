import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
	    Scanner scanner = new Scanner(System.in);

	    long A = Long.parseLong(scanner.next());
	    long B = Long.parseLong(scanner.next());

	    if (B<A) {
	    	A=A^B;
	    	B=A^B;
	    	A=A^B;
	    }
	    long r = 0;
	    long a=A;
	    long b=B;
	    while(true) {
	        long y = b%a;
	        if (y == 0) {
	        	r = a;
	        	break;
	        } else {
	        	b = a;
	        	a = y;
	        }
	    }


        System.out.print(A*B/r);
	}

}
