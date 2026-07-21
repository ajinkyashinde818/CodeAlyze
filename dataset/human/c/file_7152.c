#include<stdio.h>
 
int main( ) {
    int height;
    int width;
    int i,j;
 
    while( 1 ) {
            scanf("%d %d" ,&height ,&width );
            if( height == 0 && width == 0) {
                break;
            }
 
        for( i = 0; i < height; i++ ) {
            for( j = 0; j < width; j++ ) {
				switch (i % 2) {
					case 0:					
						if( j % 2 == 0) { 
							printf("#");
						}else{
							printf(".");
						}
						break;
					case 1:
						if( j % 2 == 1) { 
							printf("#");
						}else{
							printf(".");
						}
						break;
				}
            }
            printf("\n");
        }
            printf("\n");
    }
    return 0;
}
