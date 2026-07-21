#include <stdio.h>

int main( int argc, char* argv[] )
{
		int h, w ;
		int i,  j;
		
		while(1)
		{
				scanf( "%d %d", &h, &w );
				if( h == 0 && w == 0 ) break;

				for( i=0; i<h; i++ ){
						if( i%2 ){
								for( j=0; j<w; j++ ){
										if( j%2 ){ printf("#");}
										else{ printf(".");}
								}
						}else{
								for( j=0; j<w; j++ ){
										if( j%2 ){ printf(".");}
										else{ printf("#");}
								}
						}
						printf("\n");
				}
				printf("\n");
		}

		return 0;
}
