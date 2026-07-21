public class
Main
{
  private static final int N = 100;

  private static int
  c2d (
    final char ch
    )
  {
    return ( Character.isLowerCase ( ch ) ? ch - 'a' : 26 + ch - 'A' );
  }

  private static char
  d2c (
    int d
    )
  {
    return ( d < 26 ? (char)( d + 'a' ) : (char)( d - 26 + 'A' ) );
  }

  public void
  run (
    final java.util.Scanner sc,
    final java.io.PrintStream out
    )
  {
    int[ ] k = new int[ N ];
    int i; 

    for ( ; ; )
    {
      String s;
      int n;

      n = sc.nextInt ( );
      if ( n == 0 ) break ;
      for ( i = 0; i < n; ++i )
        k[ i ] = sc.nextInt ( );
      s = sc.next ( );

      for ( i = 0; i < s.length ( ); ++i )
        out.print ( d2c ( ( c2d ( s.charAt ( i ) ) + 52 - k[ i % n ] ) % 52 ) );
      out.println ( );
    }
  }

  public static void
  main (
    final String[ ] args
    )
  {
    ( new Main ( ) ).run ( new java.util.Scanner ( System.in ), System.out );
  }
}
