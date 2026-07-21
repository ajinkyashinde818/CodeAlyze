#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d",&N);
	int A[N+1],B[N+1],C[N];
	int i;
	A[0] = 10000; B[0] = 100000;
	for(i=1;i<N+1;i++) scanf("%d",&A[i]);
	for(i=1;i<N+1;i++) scanf("%d",&B[i]);
	for(i=1;i<N;i++) scanf("%d",&C[i]);
	int ans = 0;
	/*
	for(i=1;i<N+1;i++){
		printf("i = %d, A[i] = %d, B[i] = %d",i,A[i],B[i]);
		if(i!=N) printf("C[i] = %d",C[i]);
		printf("\n");
	}
	*/
	int pre_A;
	pre_A = A[1];
	for(i=1;i<N+1;i++){
		ans += B[A[i]];
		if(A[i] == pre_A + 1)
		{
			//printf("C\n");
			ans += C[pre_A];
		}
		pre_A = A[i];
		//printf("ans = %d\n",ans);
	}
	printf("%d",ans);
	
	return 0;
}
