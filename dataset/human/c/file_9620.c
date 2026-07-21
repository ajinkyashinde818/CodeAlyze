#include <stdio.h>

#define N 100

int compare (
  const char  * m,
  const char  * s
  )
{
  for ( ; *m != '\0'; ++m, ++s )
  {
    if ( *m == '*' || *m == *s )  continue ;

    return ( 0 );
  }

  return ( 1 );
}

/** Application main entry point. */
int main (
  int     argc,
  char  * argv[ ]
  )
{
  int i, j;

  for ( ; ; )
  {
    struct
    {
      char  cond[ 12 ];
      int   value;
    } d[ N ];
    char src[ 12 ];
    int res = 0;
    int n, m;

    scanf ( " %d %d", &n, &m );
    if ( !( n | m ) ) break ;

    for ( i = 0; i < n; ++i )
    {
      scanf ( " %s %d", d[ i ].cond, &d[ i ].value );
    }

    for ( j = 0; j < m; ++j )
    {
      scanf ( " %s", src );
      for ( i = 0; i < n; ++i )
      {
        res += compare ( d[ i ].cond, src ) * d[ i ].value;
      }
    }

    printf ( "%d\n", res );
  }

  return ( 0 );
}
