import java.util.*;
import java.io.*;

class Main {

    public static void main(String[] args) {

	final Scanner stdin = new Scanner(System.in);

	while ( true ) {

	    final int m = stdin.nextInt();
	    final int n = stdin.nextInt();

	    if ( n == 0 && m == 0 ) {
		break;
	    }	    

	    int[] ws = new int[n];
	    for ( int i = 0; i < n; i++ ) {
		ws[i] = stdin.nextInt();
	    }

	    int right = 1500000;
	    int left = 0;
	    for ( int i = 0; i < 100; i++ ) {
		final int middle = ( right + left ) / 2;
		if ( canPut( ws, middle, m ) ) {
		    right = middle;
		} else {
		    left = middle;
		}
	    }
	    System.out.println( right );
	}	
    }

    static int sum( int[] ar ) {
	int sum = 0;
	for ( int a : ar ) {
	    sum += a;
	}
	return sum;
    }

    static int min( int[] ar ) {
	int min = Integer.MAX_VALUE;
	for ( int a : ar ) {
	    min = Math.min( min, a );
	}
	return min;
    }

    static boolean canPut( int[] ws, int maxWidth, int m ) {
	int count = 1;
	int wSum = 0;
	for ( int w : ws ) {
	    if ( w > maxWidth ) {
		return false;
	    }
	    if ( wSum + w <= maxWidth ) {
		wSum += w;
	    } else {
		count++;
		wSum = w;
	    }
	}
	return count <= m;
    }    
}
