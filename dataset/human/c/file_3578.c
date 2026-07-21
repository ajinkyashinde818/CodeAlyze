#include <stdio.h>
#include <stdlib.h>

int
main (
  int   argc,
  char *argv[ ]
  )
{
  int res = 0;
  int i;

  for ( i = 0; i < 10; ++i )
  {
    int d;

    scanf ( "%d", &d );
    res += d;
  }

  printf ( "%d\n", res );

  return ( EXIT_SUCCESS );
}
