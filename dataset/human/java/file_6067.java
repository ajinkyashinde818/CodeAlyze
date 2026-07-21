import java.io.*;
import java.util.*;

class Main {

    void solve(){

	Scanner sc = new Scanner( System.in );
	int c = 0, n = sc.nextInt();

	while ( n > 1 ) {
	    n >>= 1;
	    ++c;
	}

	System.out.println( 1<<c );
    }

    public static void main( String[] a ) { new Main().solve(); }
}
