#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
	int K,N;
	scanf("%d %d",&K,&N);
	int A[N];
	for(int i=0; i<N; i++){
		scanf("%d",&A[i]);
	}
	
	int min = K;
	for(int i=0; i<N-1; i++){
		if(K - (A[i+1] - A[i]) < min){
			min = K - (A[i+1] - A[i]);
		}
	}
	if(min > A[N-1] -A[0]){
		min = A[N-1] -A[0];
	}

	printf("%d\n",min);
	return 0;
}
