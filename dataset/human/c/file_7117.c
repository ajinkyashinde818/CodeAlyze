#include <stdio.h>
int main(void){
int i=0;
int j=0;
int w=0;
int h=0;
int d=0;
	while(1){
	scanf("%d %d", &h, &w);
	if (w==0 && h==0) break;
		for ( i = 0; i < h; i++ ){
				for ( j = 0; j < w; j++ ){
					d=(i+j) % 2;
					if (d==1) {
					printf(".");
					}else{
					printf("#");
					}
				}
		printf("\n");
		}
	printf("\n");
	}
return 0;
}
