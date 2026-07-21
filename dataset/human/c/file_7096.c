#include <stdio.h>

int main(void)
{
	int h, w;
	unsigned short i, j;

	while(1){
		scanf("%d %d", &h, &w);
		getchar();
		if(h==0 && w==0){ break; }
		
		for(i=0; i<h; i++){
			for(j=0; j<w; j++){
				if(i%2 == 1){
					if(j%2 == 1){
						printf("#");
					}else{
						printf(".");
					}
				}else{
					if(j%2 == 1){
						printf(".");
					}else{
						printf("#");
					}
				}
			}
			printf("\n");
		}
		
		printf("\n");
	}
	return 0;
}
