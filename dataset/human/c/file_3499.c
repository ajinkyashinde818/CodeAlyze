#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long n, k;
int a[200001];
int f[200001];

int main( int argc, char *argv[] )
{
    int c = 1;
    int l = -1;

    scanf( "%lld %lld", &n, &k );
    for( int i=1; i<=n; i++ )
        scanf( "%d", &a[i] );

    for( int i=1; i<=n; i++ ) {
        f[c] = i;
//printf( "%d\n", c );
        c = a[c];
        if( f[c] > 0 ) {
            l = i + 1;
            break;
        }
    }

//printf( "c = %d\n", c );
//printf( "l = %d\n", l );
//for( int i=1; i<=n; i++ )
//printf( "a[%d] = %d     f[%d] = %d\n", i, a[i], i, f[i] );

    int lim = l - f[c];
//    printf( "cycle = %d\n", lim );

    if( k < l ) {
        c = 1;
        for( int i=0; i<k; i++ ) c = a[c];
        printf( "%d\n", c );
        exit( 0 );
    }

    k -= l - 1;

    for( int i=0; i<(k%lim); i++ ) c = a[c];

    printf( "%d\n", c );
}
