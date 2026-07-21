#include <stdio.h>

int main( void ) {
    int h, w;
    int x, y;

    while ( scanf( "%d %d", &h, &w ), ( h > 0 && w > 0 ) ) {
        for ( y = 1; y <= h; y ++ ) {
            for ( x = 1; x <= w; x ++ ) {
                if ( ( x + y ) % 2 == 0 ) {
                    printf( "#" );
                }
                else {
                    printf( "." );
                }
            }
            printf( "\n" );
        }
        printf( "\n" );
    }

    /* printf( "\n" ); */
    return 0;
}
