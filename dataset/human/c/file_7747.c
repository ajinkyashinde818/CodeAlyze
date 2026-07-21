#include<stdio.h>
int main(void)
{
    int N, K, P, b, i;
	
	scanf("%d",&N);
	for(i=0;i<N;i++){
	    scanf("%d",&K);
	    scanf("%d",&P);
		b=K%P;
	if (b==0){
	   b=P;
	}
	printf("%d\n",b);
	}
	return 0;
}
