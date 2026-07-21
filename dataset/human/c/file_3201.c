#include <stdio.h>

int main(void){
	int K, N, i, AM;
	AM = 0;
	
	scanf("%d %d", &K, &N);

	int A[200000] = {};
	
	for(i = 1; i<=N; i++){
		scanf("%d", &A[i]);
	}
	
	for(i = 1; i<=N; i++){
		if(i == N){
			if(AM < (K-A[N])+A[1]) AM = (K-A[N])+A[1];
		}
		
		else if(AM < A[i+1] - A[i]) AM = A[i+1] - A[i];
	}
	
	printf("\n%d", K - AM);
	
	return 0;
}
