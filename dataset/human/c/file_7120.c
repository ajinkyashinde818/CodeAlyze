#include<stdio.h>

int main(){
	int H,W,i,j;
	
	while(1){
		scanf("%d %d",&H,&W);
		
		if(H==0 && W==0) break;
		
		for(i=0;i<H;i++){
			if(i%2==0){//奇数行
				for(j=0;j<W;j++){
					if(j%2==0){//奇数列
						printf("#");
					}else{//偶数列
						printf(".");
					}
				}
			}else{//偶数行
				for(j=0;j<W;j++){
					if(j%2==0){//奇数列
						printf(".");
					}else{//偶数列
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
