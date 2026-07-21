#include <stdio.h>

#define MAX_N 128

int main(void){
	int n;
	int h[MAX_N],w[MAX_N];
	int temph,tempw;
	int i,j,k;
	n=0;
	do{
		scanf("%d %d",&temph,&tempw);
		if (temph!=0 || tempw!=0){
			h[n]=temph;
			w[n]=tempw;
			n++;
		}
	}while (temph!=0 || tempw!=0);
	for (i=0;i<n;i++){
		//??????????????????i??????????????????
		for (j=0;j<h[i];j++){
			for (k=0;k<w[i];k++){
				if (j%2==0){
					if (k%2==0){
						printf("#");
					}
					else{
						printf(".");
					}
				}
				else{
					if (k%2==0){
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
