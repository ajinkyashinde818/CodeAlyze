#include <stdio.h>

int main(void)
{	
	int H,W,i,j;

	while(1){
		scanf("%d %d",&H,&W);
		if(H==0 && W==0)
			break;
		for(i=0; i<H; i++){
			for(j=0; j<W; j++)
				if((j+i)%2)
					printf(".");
				else
					printf("#");
			puts("");
		}
		puts("");
	}

	return 0;
}
