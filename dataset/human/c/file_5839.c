#include <stdio.h>

#define N 200000

int main () {
    int i = 0,
        num = 0,
        inp = 0,
        maxv = 0, 
        minv = 0,
        array[N];

    scanf( "%d", &num );
    for ( i=0; i<num; i++ ) {
        scanf( "%d", &array[i] );
    }

    minv = array[0];
    maxv = array[1]-array[0];
    for ( i=1; i <= num-1; i++ ) {
        if ( maxv < array[i]-minv ) maxv = array[i]-minv;
        if ( minv > array[i] ) minv = array[i];
    }
    printf( "%d\n", maxv );

    return 0;
}
