#include<stdio.h>
int main(void)
{
	int H,W,i,j;
	
	while(1){
		scanf("%d %d",&H,&W);
		if(H == 0 && W == 0) break;
		for(i=0;i<H;i++){
			for(j=0;j<W/2;j++){
				if(i % 2) printf(".#");
				else printf("#.");
			}
			if(W % 2 == 1 && i % 2 ==0) putchar('#');
			if(W % 2 == 1 && i % 2 ==1) putchar('.');
			puts("");
		}
		puts("");
	}
	return 0;
}
