#include <stdio.h>
#include <ctype.h>

static int
mtoi (
  const char * s
  )
{
  int res = 0;
  int t = 1;

  for ( ; *s != '\0'; ++s )
  {
    if ( isdigit ( *s ) ) t = *s - '0';
    else
    {
      switch ( *s )
      {
        case 'm': t *= 1000; break ;
        case 'c': t *= 100;  break ;
        case 'x': t *= 10;   break ;
      }

      res += t;
      t = 1;
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
  int n;

  scanf ( "%d", &n );
  while ( n-- )
  {
    char s[ 2 ][ 1024 ];
    int  r[ 4 ];
    int  res;

    scanf ( " %s %s", s[ 0 ], s[ 1 ] );
    res = mtoi ( s[ 0 ] ) + mtoi ( s[ 1 ] );
    r[ 0 ] = res / 1000;
    r[ 1 ] = ( res % 1000 ) / 100;
    r[ 2 ] = ( res % 100 ) / 10;
    r[ 3 ] = res % 10;

    if ( r[ 0 ] )
    {
      if ( r[ 0 ] > 1 ) printf ( "%d", r[ 0 ] );
      printf ( "m" );
    }
    if ( r[ 1 ] )
    {
      if ( r[ 1 ] > 1 ) printf ( "%d", r[ 1 ] );
      printf ( "c" );
    }
    if ( r[ 2 ] )
    {
      if ( r[ 2 ] > 1 ) printf ( "%d", r[ 2 ] );
      printf ( "x" );
    }
    if ( r[ 3 ] )
    {
      if ( r[ 3 ] > 1 ) printf ( "%d", r[ 3 ] );
      printf ( "i" );
    }
    puts ( "" );
  }

  return ( 0 );
}
