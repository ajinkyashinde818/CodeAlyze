#include<stdio.h>
int main(void)
{
    int N,K,P,i,n,W;
	scanf("%d",&N);
	for(i=0;i<N;i++){
	    scanf("%d %d",&K,&P);
		W=K;
		for(n=0;n<K;n++){
			if(W<=P){
			    break;
			}
			W=W-P;
		}
		printf("%d\n",W);
	}
	return 0;
}
