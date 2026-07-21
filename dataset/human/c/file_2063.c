#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 20
#define N 100
#define INF 100000000
#define MIN(A,B) \
  ( (B) < (A) ? (B) : (A) )
#define MAX(A,B) \
  ( (B) > (A) ? (B) : (A) )

static int k_operafan[ M + 1 ][ N ];

static int d[ N ];

static int
dpFSA (
  int m,
  int n
  )
{
  int i;

  if ( n < 0 )  return ( 0 );
  if ( m == 0 ) return ( INF );

  if ( ~k_operafan[ m ][ n ] ) ;
  else
  {
    int width = 0;

    k_operafan[ m ][ n ] = INF;
    for ( i = n; i >= 0; --i )
    {
      width += d[ i ];
      k_operafan[ m ][ n ] = MIN( k_operafan[ m ][ n ]
                                , MAX( width, dpFSA ( m - 1, i - 1 ) ) );
    }
  }

  return ( k_operafan[ m ][ n ] );
}

int
main (
  int   argc,
  char *argv[ ]
  )
{
  int i;

  for ( ; ; )
  {
    int m, n;

    scanf ( "%d%d", &m, &n );
    if ( m == 0 && n == 0 )
      break ;

    for ( i = 0; i < n; ++i )
      scanf ( "%d", &d[ i ] );

    memset ( k_operafan, -1, sizeof ( k_operafan ) );
    printf ( "%d\n", dpFSA ( m, n - 1 ) );
  }

  return ( EXIT_SUCCESS );
}
