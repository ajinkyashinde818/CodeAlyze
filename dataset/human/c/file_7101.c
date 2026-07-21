#include <stdio.h>

int main(void)
{
	int H,W,i,k;
	while(1){
		scanf("%d %d",&H,&W);
		if(H==0 && W==0){
			break;
		}
		for(i=0;i<H;i++){
			for(k=0;k<W;k++){
				if(!(i%2)){
					if(!(k%2)){
						printf("#");
					}
					else {
					printf(".");
					}
				}

				else {
					if(!(k%2)){
						printf(".");
					}
					else{
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
