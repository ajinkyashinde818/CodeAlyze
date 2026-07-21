#include <stdio.h>

#define MAX 10000

int main( void )
{
  int n[MAX];
  for ( int i = 0; i < MAX; ++i ) {
    scanf( "%d", n + i );
  }
  for ( int i = 0; i < MAX; ++i ) {
    if ( n[i] == 0 ) {
      break;
    }
    printf( "Case %d: %d\n", i + 1, n[i] );
  }
return 0;
}
