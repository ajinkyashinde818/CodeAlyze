#include <stdio.h>

int h,w,x,y,z;
char masu[100][100];

int main(){



    scanf ( " %d %d " , &h , &w );

    for ( x = 1 ; x < h ; x++ ) scanf ( " %s " , &masu[x] );


    for ( x = 1 ; x <= h ; x++ ) {
        for ( y = 1 ; y <= w ; y++ ) {
            if ( masu[x][y] != '#' ) masu[x][y] = 0;
        }
    }


    for ( x = 1 ; x <= h ; x++ ) {
        for ( y = 1 ; y <= w ; y++ ) {
            if ( masu[x][y] == '#' ){
                if( masu[x-1][y] == 0 && masu[x][y-1] == 0 && masu[x+1][y] == 0 && masu[x][y+1] == 0 ) {
                    printf("No\n");
                    return 0;
                }
            }
        }
    }


    printf("Yes\n");



    return 0;
}
