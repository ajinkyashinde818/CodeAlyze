#include<stdio.h>

int main(void)
{
	int N,K,P,n,m;

scanf("%d",&N);

	for( n=0; n<N; n++ ){
		scanf("%d %d",&K,&P);
		m=K%P;
		if( m==0 ){
			printf("%d\n",P);
		}
		else{
			printf("%d\n",m);
		}

	}
	return 0;
}
