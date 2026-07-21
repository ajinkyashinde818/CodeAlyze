/*
 ============================================================================
 Name        : ABC160-C.c
 Author      : shigu-shigu_rain
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int K, N, slong, mlong;
int main(void) {
	scanf("%d %d", &K, &N);
	int A[N+2];
	int B[N+2];
	for(int i = 0; i < N+2; i++){
		A[i]=0;
		B[i]=0;
	}
	scanf("%d", &A[0]);
	for(int j = 1; j < N; j++){
		scanf("%d", &A[j]);
		B[j] = A[j] - A[j-1];
	}

	B[0] = K - A[N-1] + A[0];
	B[N] = K - A[N-1] + A[0];

	int x = 1;
	while(x <= N){
		if(B[x] > (K - A[x-1]) / 2){
			if(B[x] > mlong){
				mlong = B[x];
				break;
			}else break;
		}else if(B[x] > mlong){
			mlong = B[x];
		}

		x++;
	}

	printf("%d", (K - mlong));

	return 0;
}
