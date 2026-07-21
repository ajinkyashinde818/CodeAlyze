#include <stdio.h>

int main( int argc, char *argv[] )
{
    long long k, n;
    long long a[200000];
    long long max = 0;

    scanf( "%lld %lld", &k, &n );
    for( int i=0; i<n; i++ ) scanf("%lld", &a[i] );


//    for( int i=0; i<n; i++ )
//    printf( "%lld\n", a[i] );

    a[n] = k+a[0];

    for( int i=0; i<n; i++ ) {
        if( a[i+1] - a[i] > max ) max = a[i+1] - a[i];
    }
    printf( "%lld\n", k - max );
}
