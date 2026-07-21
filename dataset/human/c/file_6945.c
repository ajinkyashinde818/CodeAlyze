/*
    2014.06.26
    C language Lecture week 3
*/

#include <stdio.h>
#include <stdlib.h>

#define Block       64

int main (void) {
    
    char str_1[512];    // 上下端で使う奴
    char str_2[512];    // その他用
    
    int height = 1;
    int width = 1;
    
    while(1){
        
        scanf ( "%d %d", &height, &width );
        
        if ( height == 0 && width == 0 ){
            break;
        }
        
        for ( int cnt = 0; cnt < ( width + 1 ) / 2; cnt ++ ) {
            str_1[cnt*2+0] = '#';
            str_1[cnt*2+1] = '.';
            str_2[cnt*2+0] = '.';
            str_2[cnt*2+1] = '#';
        }
        str_1[width] = '\0';
        str_2[width] = '\0';
        
        for ( int cnt = 0; cnt < height; cnt ++ ){
            if ( cnt % 2 == 0 ){
                printf ( "%s\n", str_1 );
            } else {
                printf ( "%s\n", str_2 );
            }
        }
        printf ( "\n" );
        
    }
    
    return 0;
    
}
