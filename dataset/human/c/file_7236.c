#include<stdio.h>
int main(){
	int H,W,i=0,j,k,l,tmp1=1,tmp2=0;
	
	while(1){
		scanf("%d %d",&H,&W);
		if(H==0&&W==0)break;
		tmp1=1;
		for(i=0;i<H;i++){
			tmp1=1-tmp1;tmp2=0;
			for(j=0;j<W;j++){
				tmp2=1-tmp2;
				if(!tmp1&&tmp2||tmp1&&!tmp2)printf("#");
				else printf(".");	
			}
			printf("\n");
		}
		printf("\n");	
	}
	
	return 0;
}
