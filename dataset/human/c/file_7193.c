#include <stdio.h>

int main(){
   int H,W,i,j;
	while(scanf("%d %d",&H,&W),H+W!=0){
		for(i=1;i<=H;i++){
			for(j=1;j<=W;j++){
				if((i+j)%2==0) printf("#");
			else printf(".");
		  }
		printf("\n");
	 }
	printf("\n");
}
return 0;
}
