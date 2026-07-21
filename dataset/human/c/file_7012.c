#include<stdio.h>
main()
{
	int H,W,i,j;
	while(1){
		scanf("%d %d",&H,&W);
		if(H==0&&W==0){
			break;
		}
		for(i=0;i<H/2;i++){
			
			for(j=0;j<W/2;j++){
				printf("#.");
			}
			if(W%2==1){
				printf("#");
			}
			printf("\n");
			
			for(j=0;j<W/2;j++){
				printf(".#");
			}
			if(W%2==1){
				printf(".");
			}
			printf("\n");
		}
		if(H%2==1){
			for(j=0;j<W/2;j++){
				printf("#.");
			}
			if(W%2==1){
				printf("#");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
