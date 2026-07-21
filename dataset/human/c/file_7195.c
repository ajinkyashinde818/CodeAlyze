#include<stdio.h>
int main(){
	int H,W;
	int i,j;
	int count=0;
	while(~scanf("%d %d",&H,&W)){
		count = 0;
		if(H==0&&W==0) break;
		for(i=0;i<H;i++){
			for(j=0;j<W;j++){
			if(count%2==0) putchar('#');
			else if(count%2==1) putchar('.');
			count++;
			}
			putchar('\n');
			if(W%2==0) count++;
		}
		putchar('\n');
	}
	return 0;
}
