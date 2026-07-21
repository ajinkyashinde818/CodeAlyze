#include <stdio.h>

#define M 10000
#define N 512
#define MIN(A,B) \
  ( (A) < (B) ? (A) : (B) )
#define MAX(A,B) \
  ( (A) > (B) ? (A) : (B) )

/** Application main entry point. */
int main (
  int     argc,
  char  * argv[ ]
  )
{
  int i;

  for ( ; ; )
  {
    int d[ M ][ 2 ];
    int c[ N ] = { 0, 1, 0 };
    int r[ N ] = { 0 };
    int res = 0;
    int n, m;

    scanf ( "%d%d", &n, &m );
    if ( !( n | m ) ) break ;

    for ( i = 0; i < m; ++i )
    {
      int a, b;

      scanf ( "%d%d", &a, &b );
      d[ i ][ 0 ] = MIN( a, b );
      d[ i ][ 1 ] = MAX( a, b );
      if ( d[ i ][ 0 ] == 1 ) c[ d[ i ][ 1 ] ] = 1;
    }

    for ( i = 0; i < m; ++i )
    {
      r[ d[ i ][ 1 ] ] |= c[ d[ i ][ 0 ] ];
      r[ d[ i ][ 0 ] ] |= c[ d[ i ][ 1 ] ];
    }
    for ( i = 2; i <= n; ++i )
    {
      res += r[ i ];
    }

    printf ( "%d\n", res );
  }

  return ( 0 );
}
