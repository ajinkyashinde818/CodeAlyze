#include <stdio.h>

#define N      10000
#define P10000 104743

static
int p[ N ];
static
int q[ P10000 + 1 ] = { 0 };

/** Application main entry point. */
int main (
  int     argc,
  char  * argv[ ]
  )
{
  int i, j, k;

  k = 0;
  for ( i = 2; i <= P10000; ++i )
  {
    if ( q[ i ] ) continue ;

    p[ k++ ] = i;
    for ( j = i; j <= P10000; j += i )
    {
      q[ j ] = 1;
    }
  }

  for ( ; ; )
  {
    int res = 0;
    int n;

    scanf ( "%d", &n );
    if ( !n ) break ;

    for ( i = 0; i < n; ++i )
    {
      res += p[ i ];
    }

    printf ( "%d\n", res );
  }

  return ( 0 );
}
