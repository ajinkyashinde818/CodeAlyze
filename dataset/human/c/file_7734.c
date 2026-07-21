#include<stdio.h>
int main(void)
{
	int K,P,N,i,j,KP;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d %d",&K,&P);
		if(K%P==0){
			printf("%d\n",P);
		}
		else{
			KP=K%P;
			printf("%d\n",KP);
		}
	}
	return 0;
}
