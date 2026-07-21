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

      int[] ks = new int[n];
      for(int i = 0; i < n; ++i) {
        ks[i] = ni();
      }
      char[] str = sc.next().toCharArray();
      
      HashMap<Character, Integer> map = new HashMap<Character, Integer>();
      HashMap<Integer, Character> rmap = new HashMap<Integer, Character>();
      for(int i = 0; i < 26; ++i) {
        map.put( (char) ( 'A' + i ), i + 26 );
        rmap.put( i + 26, (char) ( 'A' + i ) );
      }
      for(int i = 0; i < 26; ++i) {
        map.put( (char) ( 'a' + i ), i );
        rmap.put( i, (char) ( 'a' + i ) );
      }
      //debug(map.entrySet());
      
      for(int i = 0; i < str.length; ++i) {
        int idx = (map.get( str[i] ) + 26*2 - ks[i%n])%52;
        str[i] = (char)rmap.get( idx );
      }
      
      System.out.println(new String(str));
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
