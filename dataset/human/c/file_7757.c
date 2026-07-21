#include<stdio.h>
int main(void)
{
	int i,N,K,P;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d %d",&K,&P);
		if(K % P != 0)
			printf("%d\n",K%P);
		else
			printf("%d\n",P);
	}
	return 0;
}
