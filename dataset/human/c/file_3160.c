#include <stdio.h>
 
int main(void) {
	int K, N;
	int A[200000];
	int max = 0;
	int i;
	
    scanf("%d %d", &K , &N);
	scanf("%d", &A[0]);
	
	for( i = 1; i < N; i++ ) {
		scanf("%d", &A[i]);
		if( (A[i] - A[i-1]) > max ) {
			max = A[i] - A[i-1];
		}
	}
	if( (K - A[N-1] + A[0]) > max ) {
		max = K - A[N-1] + A[0];
	}
 
	printf("%d", (K - max));
 
	return 0;
}
