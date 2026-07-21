#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>
#include<ctype.h>


//main関数
int main() {
	long long N,K;
	scanf("%lld %lld",&N,&K);
	
	long long A[N];
	for( long long i=0; i<N; i++ ) {
		scanf("%lld",&A[i]);
		A[i] = A[i] -1;
	}
	
	long long array[N];
	for( long long i=0; i<N; i++ ) {
		array[i] = -1;
	}
	
	long long memory = 0;
	long long sakoda = 1;
	long long amari = 0;
	
	for( long long i=0; i<N ; i++ ) {
		if (array[memory] != -1) {
			sakoda = i - array[memory];
			amari = array[memory];
			K = K - amari;
			K = K % sakoda;
			break;
		}
		array[memory] = i;
		memory = A[memory];
		if( i == K ){
			break;
		}
	}
	
	for(long long i=0;i<N;i++){
		if( array[i] - amari == K ) {
			printf("%lld",i+1);
			return 0;
		}
	}
}
