#include<stdio.h>

int main(void){
	int i,j,k,l;
	
	while(1){
		
		scanf("%d %d",&i,&j);
		
		if(i == 0 && j == 0){
			break;
		}
		
		for(k = 1;k <= i;k++){
			switch(k % 2){
				case 0:
					for(l = 1;l <= j;l++){
						if(l % 2 == 0){
							printf("#");
						}else{
							printf(".");
						}
					}
					break;
				case 1:
					for(l = 1;l <= j;l++){
						if(l % 2 == 0){
							printf(".");
						}else{
							printf("#");
						}
					}
					break;
			}
			printf("\n");
		}
		printf("\n");
	}
	
	return(0);
}
