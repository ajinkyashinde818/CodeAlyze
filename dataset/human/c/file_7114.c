#include <stdio.h>

int main(void){

	int h, w;
	int i, j, k;
	
	while(1){
		scanf("%d %d", &h, &w);
		if(h == 0 && w == 0){
			break;
		}
		
		for(i = 0; i < h; i++){
			if(i % 2 == 0){
				for(k = 0; k < w; k++){
					if(k % 2 == 0){
						putchar('#');
					}else{
						putchar('.');
					}
				}
			}else{
				for(k = 0; k < w; k++){
					if(k % 2 == 0){
						putchar('.');
					}else{
						putchar('#');
					}
				}
			}
			putchar('\n');
		}
		putchar('\n');
	
	}
	
	return 0;
}
