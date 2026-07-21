#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>
#include<ctype.h>

//qsort
int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

//比較
int max(int a, int b){
	if (a>b) return a;
	else return b;
}

int min(int a,int b) {
	if(a>b) return b;
	else return a;
}


//main関数
int main() {
	long long N,K;
	scanf("%lld %lld",&N,&K);
	
	long long A[N];
	for( int i=0; i<N; i++){
		scanf("%lld",&A[i]);
	}
	
	qsort(A, N, sizeof(long long), compare_int);
	
	if( K == 0){
		printf("%lld", A[N-1]);
		return 0;
	}
	
	long long left = 0; long long right = A[N-1]; long long mid;
	long long sum = 0;
	while(right > left+1){
		mid = (right+left) / 2;
		sum = 0;
		for( long long i=0; i<N ; i++ ){
			if(A[i] > mid){
				sum += A[i] / mid;
			}
		}
		if( sum > K ) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	printf("%lld",right);
}
