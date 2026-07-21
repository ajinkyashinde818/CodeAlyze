#include<stdio.h>

int main(void){
	int a,i,j,H,M;
	while(1){
	scanf("%d %d",&H,&M);
	if(H == 0 && M == 0)break;
	for ( i = 1; i <= H; i++ ){
		for ( j = 1; j <= M; j++ ){
			if((i+j)%2 == 0){
				printf("#");
			}else{
				printf(".");
			}
		}
		printf("\n");
	}
	printf("\n");
	}
	return 0;
}
