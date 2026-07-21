#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
	int N, K;
	scanf("%d %d",&N,&K);
	int hight[N];
	for (int i = 0; i < N; i++) {
		scanf("%d",&hight[i]);
	}
	qsort(hight, N, sizeof(int), compare_int);
	int tmp = 0;
	for (tmp = 0; tmp < N; tmp++) {
		if (hight[tmp] >= K) break;
	}
	printf("%d\n",N - tmp);
	return 0;
}
