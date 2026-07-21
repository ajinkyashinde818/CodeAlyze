#include<stdio.h>
int main(void)
{
	int i,K,N,P;
	int A[1000];
	scanf("%d",&N);
	for(i=1;i<=N;i++){
	scanf("%d %d",&K,&P);
	if(K%P !=0){
		A[i]=K%P;
	}
	else{
		A[i]=P;
	}
	}
	for(i=1;i<=N;i++){
		printf("%d\n",A[i]);
	}
	return 0;
}
