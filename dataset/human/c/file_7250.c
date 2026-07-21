#include<stdio.h>
int main (void){
	int h = 0;
	int w = 0;
	int ch = 0;
	int cw = 0;
	while(1){
		scanf("%d %d",&h,&w);
		if((h == 0)&&(w == 0)){
			break;
		}
		for(ch = 0;ch < h;ch++){
			if(ch % 2 == 0){
				for(cw = 0;cw < w;cw++){
					if(cw % 2 == 0){
						printf("#");
					}else{
						printf(".");
					}	
				}
				printf("\n");
			}else{
				for(cw = 0;cw < w;cw++){
					if(cw % 2 == 0){
						printf(".");
					}else{
						printf("#");
					}	
				}
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}
