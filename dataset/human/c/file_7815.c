#include <stdio.h>

int main(void)
{
	int i,N,K[100],P[100],a[100];
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d %d",&K[i],&P[i]);	
		if(P[i]>K[i]){
			a[i]=K[i];
		}
		else if(K[i]%P[i]==0){
			a[i]=P[i];
		}
		else{
			a[i]=K[i]%P[i];
		}
	}
	for(i=0;i<N;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}
