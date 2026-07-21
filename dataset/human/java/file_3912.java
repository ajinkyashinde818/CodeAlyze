import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
  Scanner sc;

  class Pair {
    int f;
    int s;

    Pair(int f_, int s_) {
      f = f_;
      s = s_;
    }
  }

  void run() {
    for ( ;; ) {
      int n = ni();

      if ( n == 0 ) {
        break;
      }

      char[][] strs = new char[n][];
      for ( int i = 0; i < n; ++i ) {
        strs[ i ] = sc.next().toCharArray();
      }

      // phase 1
      int[] story = new int[n];
      for ( int i = 0; i < n; ++i ) {
        int idx = -1;
        for ( int j = 0; j < strs[ i ].length; ++j ) {
          if ( strs[ i ][ j ] == '.' ) {
            idx = j;
          }
        }
        story[ i ] = idx;
        if ( idx == -1 ) {
          continue;
        }
        strs[ i ][ idx ] = '+';
      }

      // phase 2
      for ( int i = 0; i < n; ++i ) {
        for ( int j = i + 1; j < n; ++j ) {
          if ( story[ i ] > story[ j ] )
            break;
          if ( story[ i ] == story[ j ] ) {
            for ( int k = i + 1; k < j; ++k ) {
              strs[ k ][ story[ i ] ] = '|';
            }
            break;
          }
        }
      }

      // phase 3
      for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < strs[ i ].length; ++j ) {
          if ( strs[ i ][ j ] == '.' ) {
            strs[ i ][ j ] = ' ';
          }
        }
      }

      for ( int i = 0; i < n; ++i ) {
        System.out.println( new String( strs[ i ] ) );
      }
    }
  }

  Main() {
    sc = new Scanner( System.in );
  }

  int ni() {
    return sc.nextInt();
  }

  public static void main(String[] args) {
    new Main().run();
  }

  void debug(Object... os) {
    System.err.println( Arrays.deepToString( os ) );
  }
}
