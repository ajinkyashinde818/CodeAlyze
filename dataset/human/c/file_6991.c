#include<stdio.h>

int main(void){
	int i, j;
	int H,W;
	
	while(1){
		scanf("%d %d",&H,&W);
		
		if(H==0&&W==0){
			break;
		}
		
		for(i=0;i<H;++i){
			for(j=0;j<W;++j){
				if(i%2!=0){
					if(j%2!=0){
						printf("#");
					}else{
						printf(".");
					}
				}if(i%2==0){
					if(j%2!=0){
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
