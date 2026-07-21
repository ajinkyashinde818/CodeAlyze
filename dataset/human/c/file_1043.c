#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
       char s[51];
       int length, f, i;

       scanf("%s", s );

       length = strlen( s );

       for( i = length; i >= 0; i-- ) //Fは後ろから何番目か
       {
              if( s[i] == 'F' )
              {
                     f = i;
                     break;
              }
       }

       for( i = 0; i <= f-1; i++ )
       {
              printf( "%c", s[i] );
       }

       printf( "\n" );
       return 0;
}
