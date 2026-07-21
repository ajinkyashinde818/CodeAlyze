#include <stdio.h>
#include <limits.h>

int main(void){
    int num;
    int maxValue;
    int minValue;
    int i;
    int r;

    maxValue = INT_MIN;
    minValue = INT_MAX;

    scanf( "%d" , &num );
    scanf( "%d" , &minValue );

    for ( i = 0 ; i < ( num - 1 ) ; i++ ){
        scanf( "%d" , &r );
        if ( maxValue < r - minValue ) {
            maxValue = r - minValue;
        }
        if ( minValue > r ) {
            minValue = r ;
        }
    }

    printf( "%d\n", maxValue );

    return 0;
}
