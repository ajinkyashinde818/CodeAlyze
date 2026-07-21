#include <stdio.h>
int main(){
	int N;
	scanf("%d",&N);
	int A[N];
	int B[N];
	int C[N];
	int K=0,i;
	for(i=1;i<N+1;i++){
		scanf("%d",&A[i]);
	}
	for(i=1;i<N+1;i++){
		scanf("%d",&B[i]);
	}
	for(i=1;i<N;i++){
		scanf("%d",&C[i]);
	}
	
	for(i=1;i<N+1;i++){
		K=K+B[i];
		if(A[i]-A[i-1]==1){
			K=K+C[A[i-1]];
		}
	}
	printf("%d",K);
}
