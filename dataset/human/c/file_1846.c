#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
long long N,W;

int 
main(){
	long long X,K;
	static char s[100010][20];
	int A[30],B[30],C[30];

	scanf("%lld",&N);
	long long i,j;
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
		for(i=0;i<N;i++){
		scanf("%d",&B[i]);
	}
	for(i=0;i<N-1;i++){
		scanf("%d",&C[i]);
	}

	long long sum=0;
	int prev_a =0;
	for(i=0;i<N;i++){
		sum += B[A[i]-1];
		//printf("+%d\n",B[A[i]-1]);
		if(i>=1) {
			if(A[i]-prev_a==1){
				sum += C[prev_a-1];
				//printf("tt%d,%d\n",prev_a,C[prev_a-1]);
			}
		}
		prev_a = A[i];
	}
	printf("%lld\n",sum);
 return 0;
}
