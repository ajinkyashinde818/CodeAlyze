#include <stdio.h>
#include <stdlib.h>

#define N 1001
#define INT(X) \
  ( *( (const int *)(X) ) )
#define ABS(X) \
  ( (X) < 0 ? -(X) : (X) )

static
int comparator (
  const void  * a,
  const void  * b
  )
{
  return ( INT( a ) - INT( b ) );
}

/** Application main entry point. */
int main (
  int     argc,
  char  * argv[ ]
  )
{
  int V, d;
  int i;

  while ( scanf ( "%d%d", &V, &d ) == 2 )
  {
    int fib[ N + 1 ] = { 1, 2 };
    int res = 1;

    for ( i = 2; i <= V; ++i )
    {
      fib[ i ] = ( fib[ i - 2 ] + fib[ i - 1 ] ) % N;
    }
    qsort ( fib + 1, V, sizeof ( int ), comparator );

    for ( i = 2; i <= V; ++i )
    {
      if ( ABS ( fib[ i ] - fib[ i - 1 ] ) >= d )
      {
        ++res;
      }
    }

    printf ( "%d\n", res );
  }

  return ( 0 );
}
