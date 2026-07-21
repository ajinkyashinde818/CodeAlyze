#include <stdio.h>

#define MAX(A,B) \
  ( (A) > (B) ? (A) : (B) )

char  d[ 1024 ][ 1024 ];
int   n;

static int
solve (
  int x,
  int y
  )
{
  int res;
  int i;

  for ( res = 0; x + res < n && y + res < n; ++res )
  {
    for ( i = 0; i <= res; ++i )
    {
      if ( d[ y + res ][ x + i ] != '.'
        || d[ y + i ][ x + res ] != '.' )
      {
        return ( res );
      }
    }
  }

  return ( res );
}

/** Application main entry point. */
int
main (
  int     argc,
  char  * argv[ ]
  )
{
  int i;

  for ( ; ; )
  {
    int res = 0;
    int x, y;

    scanf ( " %d", &n );
    if ( !( n ) ) break ;

    for ( i = 0; i < n; ++i )
    {
      scanf ( " %s", d[ i ] );
    }

    for ( y = 0; y < n; ++y )
    for ( x = 0; x < n; ++x )
    {
      res = MAX( res, solve ( x, y ) );
    }

    printf ( "%d\n", res );
  }

  return ( 0 );
}
