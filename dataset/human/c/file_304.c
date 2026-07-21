#include <stdio.h>
#include <stdlib.h>

int main ( )
{
  int N, i, min, cnt;
  long sum;
  long A[ 100000 ];
  scanf ( "%d", &N );
  sum = 0;
  min = 1000000000;
  cnt = 0;
  for ( i = 0 ; i < N ; i++ )
    {
      scanf ( "%ld", &A[ i ] );
      if ( A[ i ] < 0 )
	{
	  cnt++;
	  A[ i ] = abs ( A[ i ] );
	}
      if ( min > A[ i ] )
	min = A[ i ];
      sum += A[ i ];
    }
  if ( cnt % 2 )
    sum -= min * 2;
  printf ( "%ld\n", sum );
  return 0;
}
