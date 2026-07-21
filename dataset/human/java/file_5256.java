import java.util.*;
import java.io.*;

class Main {

    public static void main(String[] args) {

	final Scanner stdin = new Scanner(System.in);

	while ( true ) {
	    final int size = Integer.parseInt( stdin.nextLine() );

	    if ( size == 0 ) {
		break;
	    }

	    final char[][] map = new char[size][];
	    
	    for ( int i = 0; i < size; i++ ) {
		map[i] = stdin.nextLine().toCharArray(); 
	    }

	    final int[][] acCol = new int[size][size];
	    for ( int r = 0; r < size; r++ ) {
		acCol[0][r] = ( map[0][r] == '.' ) ? 1 : 0;
		for ( int c = 1; c < size; c++ ) {
		    if ( map[c][r] == '.' ) {
			acCol[c][r] = acCol[c - 1][r] + 1;
		    } else {
			acCol[c][r] = 0;	
		    }
		}
	    }

	    final int[][] acRow = new int[size][size];
	    for ( int c = 0; c < size; c++ ) {
		acRow[c][0] = ( map[c][0] == '.' ) ? 1 : 0;
		for ( int r = 1; r < size; r++ ) {
		    if ( map[c][r] == '.' ) {
			acRow[c][r] = acRow[c][r - 1] + 1;
		    } else {
			acRow[c][r] = 0;	
		    }
		}
	    }

	    final int[][] ans = new int[size][size];
	    for ( int i = 0; i < size; i++ ) {
		ans[i][0] = ( map[i][0] == '.' ? 1 : 0 );
		ans[0][i] = ( map[0][i] == '.' ? 1 : 0 );
	    }
	    
	    int maxSize = 0;
	    for ( int c = 1; c < size; c++ ) {
		for ( int r = 1; r < size; r++ ) {
		    if ( map[c][r] == '*' ) {
			ans[c][r] = 0;
		    } else {
			if ( acRow[c][r] > ans[c - 1][r - 1] + 1 && acCol[c][r] > ans[c - 1][r - 1] + 1 ) {
			    ans[c][r] = ans[c - 1][r - 1] + 1;
			} else {
			    ans[c][r] = Math.min( acRow[c][r], acCol[c][r] );
			}
			maxSize = Math.max( maxSize, ans[c][r] );
		    }
		}
	    }
	    System.out.println( maxSize );
	}
    }
}
