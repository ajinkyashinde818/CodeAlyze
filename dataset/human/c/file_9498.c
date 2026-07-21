#include<stdio.h>

int main(void){
	int N,D,X,i,j,k = 1,choco = 0;
	int A[100];

	scanf("%d",&N);
	scanf("%d %d",&D,&X);
	for(j = 1;j <= N;j++)
		scanf("%d",&A[j-1]);

	for(i = 1;i <= N;i++){
		while(((k-1) * A[i-1] + 1) <= D){
				choco++;
				k++;
		}
		k = 1;
	}

	printf("%d\n",choco + X);

	return 0;
}
