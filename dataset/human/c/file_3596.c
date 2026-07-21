#include <stdio.h>
#include <string.h>

#define N   1121
#define PN  187

static int  p[ N ] = { 1, 1, 0 };
static int  pn = 0;

static int k_operafan[ N ][ PN ][ 15 ];

static int
dpFSA (
  int n,
  int r,
  int k
  )
{
  if ( n < 0 )    return ( 0 );
  if ( k == 0 )   return ( n == 0 );
  if ( k < 0
    || r >= pn )  return ( 0 );

  if ( ~k_operafan[ n ][ r ][ k ] ) ;
  else
  {
    k_operafan[ n ][ r ][ k ] = dpFSA ( n, r + 1, k )
                              + dpFSA ( n - p[ r ], r + 1, k - 1 );
  }

  return ( k_operafan[ n ][ r ][ k ] );
}

/** Application main entry point. */
int
main (
  int     argc,
  char  * argv[ ]
  )
{
  int i, j;

  for ( i = 2; i < N; ++i )
  {
    if ( p[ i ] ) continue ;

    p[ pn++ ] = i;
    for ( j = i * 2; j < N; j += i )
    {
      p[ j ] = 1;
    }
  }

  memset ( k_operafan, -1, sizeof ( k_operafan ) );
  for ( ; ; )
  {
    int n, k;

    scanf ( "%d%d", &n, &k );
    if ( !( n | k ) ) break ;

    printf ( "%d\n", dpFSA ( n, 0, k ) );
  }

  return ( 0 );
}
