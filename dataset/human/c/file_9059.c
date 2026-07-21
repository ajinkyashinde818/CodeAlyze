#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//int s_dsort(const void* a, const void* b);

int main(void) {
	int N,K,i,cnt=0;
	int A;
	
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++) {
		scanf("%d", &A);
		if (A < K)continue;
		cnt++;
	}
	
	printf("%d", cnt);
	return 0;
}
