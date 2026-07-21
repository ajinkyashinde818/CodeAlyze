#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define false 0
#define true (!false)
#define STRMAX (300000)

char S[STRMAX];
char pre[STRMAX];
char post[STRMAX];

int revf = false;
int Q;

void revers( char *s )
{
    int i;
    int len = strlen( s );
    char buf[STRMAX];

    strcpy( buf, s );
    for( i=0; i<len; i++ ) s[i] = buf[len - i-1];
}

int main( int argc, char *argv[] )
{
    int i;
    int t, f, c;
    char buf[128];
    char *p1 = pre;
    char *p2 = post;

    scanf( "%s", S );
    scanf( "%d", &Q );

    for( i=0; i<Q; i++ ) {

//printf( "*** %d\n", i );

        scanf( "%d", &t );
//        int n = scanf( "%d%d %c", &t, &f, &c );
//printf( "n = %d\n", n );
        if( t == 1 ) {
            revf = ! revf;
        } else if( t == 2 ) {
            scanf( "%d %c", &f, &c );
            if( f == 1 ) {
                if( ! revf ) *p1 ++ = c;
                else         *p2 ++ = c;
            } else if( f == 2 ) {
                if( ! revf ) *p2 ++ = c;
                else         *p1 ++ = c;
            }
        }
    }

    *p1 = 0;
    *p2 = 0;

    if( ! revf ) {
        revers( pre );
        strcat( pre, S );
        strcpy( S, pre );
        strcat( S, post );
    } else {
        revers( S );
        revers( post );
        strcat( post, S );
        strcpy( S, post );
        strcat( S, pre );
    }

    puts( S );
}
