#include <stdio.h>
#include <limits.h>

#define LB(X,L) \
  ( (X) > (L) ? (X) : (L) )

static
const int stage[ ] = { 4, 1, 4, 1, 2, 1, 2, 1 };
#define STAGE(X) \
  ( stage[ ( (X) + 0 ) % 8 ] * 390625 \
  + stage[ ( (X) + 1 ) % 8 ] * 78125 \
  + stage[ ( (X) + 2 ) % 8 ] * 15625 \
  + stage[ ( (X) + 3 ) % 8 ] * 3125 \
  + stage[ ( (X) + 4 ) % 8 ] * 625 \
  + stage[ ( (X) + 5 ) % 8 ] * 25 \
  + stage[ ( (X) + 6 ) % 8 ] * 5 \
  + stage[ ( (X) + 7 ) % 8 ] * 1 )

/** Application main entry point. */
int main (
  int     argc,
  char  * argv[ ]
  )
{
  int b[ 8 ];
  int i, j;

  while ( scanf ( "%d%d%d%d%d%d%d%d"
                , b, b + 1, b + 2, b + 3, b + 4
                , b + 5, b + 6, b + 7 ) == 8 )
  {
    int res = 0;
    int min = INT_MAX;
    int mii = INT_MAX;

    for ( j = 0; j < 8; ++j )
    {
      int t = 0;

      for ( i = 0; i < 8; ++i )
      {
        t += LB( b[ i ] - stage[ ( j + i ) % 8 ], 0 );
      }

      if ( ( t < min )
        || ( t == min && STAGE( j ) < mii ) )
      {
        res = j;
        min = t;
        mii = STAGE( res );
      }
    }

    for ( i = 0; i < 8; ++i )
    {
      if ( i )  putchar ( ' ' );
      printf ( "%d", stage[ ( res + i ) % 8 ] );
    }
    puts ( "" );
  }

  return ( 0 );
}
