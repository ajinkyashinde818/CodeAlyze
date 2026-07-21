#include <stdio.h>

int main(){
	int h, w, i, j;
	scanf("%d %d", &h, &w);
	while(h != 0 && w != 0){
		for(i = 0; i < h; i++){
			for(j = 0; j < w; j++){
				if(i % 2 == 0 && j % 2 == 0){
					printf("#");
				} else if(i % 2 == 0 && j % 2 == 1){
					printf(".");
				} else if(i % 2 == 1 && j % 2 == 0){
					printf(".");
				} else if(i % 2 == 1 && j % 2 == 1){
					printf("#");
				}
			}
			printf("\n");
		}
		printf("\n");
		scanf("%d %d", &h, &w);
	}
	return 0;
}
