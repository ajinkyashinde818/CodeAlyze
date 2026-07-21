#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>
#include<ctype.h>
int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main () {
	int K,N;
	scanf("%d %d",&K,&N);
	int A[N];
	for(int i=0; i<N ; i++ ) {
		scanf("%d",&A[i]);
	}
	qsort(A, N, sizeof(int), compare_int );
	
	int max = 0;
	
	for(int i=0; i<N-1 ; i++ ) {
		int sakoshun = A[i+1] - A[i];
		if (sakoshun > max) {
			max = sakoshun;
		}
	}
	int sakoda = A[0] + K - A[N-1];
	if(sakoda > max) {
		max = sakoda;
	}
	printf("%d",K-max);
	
	
	return 0;
}
