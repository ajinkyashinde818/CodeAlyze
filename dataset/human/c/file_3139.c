#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

int comp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main(void) {
	int K, N;
	int res = 0;
	scanf("%d%d", &K, &N);
	int* list;
	int* distance;
	list = (int*)malloc(sizeof(int) * N);
	distance = (int*)malloc(sizeof(int) * N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &list[i]);
	}
	for (int i = 0;i < N-1;i++) {
		distance[i] = list[i + 1] - list[i];
		res += distance[i];
	}
	distance[N-1] = K - res;
	res = 0;
	qsort(distance, N, sizeof(int), comp);
	for (int i = 0;i < N-1;i++) {
		res += distance[i];
	}
	printf("%d", res);
	free(list);
	list = NULL;
	free(distance);
	distance = NULL;
	return 0;
}
