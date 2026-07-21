#include <stdio.h>
int main(void){
	int H,Y,i,n,kei;
	while(1){
		scanf("%d %d",&H,&Y);
		if(H == 0&&Y == 0) break;
		for(i = 0;i<H;i++){
			kei = i%2;
			if(kei == 0){
				for(n = 0;n<Y;n++){
					kei = n%2;
					if(kei == 0){
						printf("#");
					}else{
						printf(".");
					}
				}
			}else{
				for(n = 0;n<Y;n++){
					kei = n%2;
					if(kei == 1){
						printf("#");
					}else{
						printf(".");
					}
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
