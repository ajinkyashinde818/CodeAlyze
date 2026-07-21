#include <stdio.h>

int main(void){
	int h,w,i,j;
	
	while(1){
		scanf("%d %d",&h,&w);
		if(h==0 && w==0) break;
		
		for(i=0;i < h;i++){
			for(j=0;j < w;j++){
				if(i % 2 == 0 && j % 2 == 0 || i % 2 == 1 && j % 2 == 1){
					printf("#");
				}else{
					printf(".");
				}
			}
			puts("");
		}
		puts("");
	}
	
	return 0;
}
