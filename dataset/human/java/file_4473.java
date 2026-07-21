import java.util.Scanner;

public class Main {
	
    public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	int A = sc.nextInt();
    	int B = sc.nextInt();
    	int C = sc.nextInt();
    	
    	int r = 0;
    	if( C > A+B+1 ) {
    		r = A+B+1;
    	}
    	else {
    		r = C;
    	}
    	System.out.println( r + B );
    	sc.close();
    }
}
