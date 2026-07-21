#include <stdio.h>

int main(void){
	int A[200000];
	int K, N;
	int k_tmp;
	int tmp = -1;
	int k_min;
	int i;

	scanf("%d %d", &K, &N);
	scanf("%d", &A[0]);
	for (i = 1; i < N; i++) {
		scanf("%d", &A[i]);
		k_tmp = A[i]-A[i-1];
		if ( k_tmp > tmp ) {
			tmp = k_tmp;
		}
	}
	k_tmp = (K-A[N-1])+A[0];
	if ( k_tmp > tmp ) { tmp = k_tmp; }

	k_min = K-tmp;
	printf("%d\n", k_min);

	return 0;
}
