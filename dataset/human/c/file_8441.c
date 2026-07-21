#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<cctype>
#include<string.h>
#include <stdlib.h>

#define PI 3.1415926
void swap(int* x, int* y) {
	int a = *x;
	int b = *y;
	*x = b;
	*y = a;
}
int factorial(int n);
int sum(int n, int*);
int ave(int n, int*);
int min(int n, int*), min(int n, int m);
int max(int n, int*), max(int n, int m);

int main() {
	int N, M, A[200];
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	for (int k = 2; k <= M; k++) {
		for (int i = 1; i <= N - 1; i++) {
			if (A[i] % k > A[i + 1] % k) {
				swap(&A[i], &A[i + 1]);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		printf("%d\n", A[i]);
	}
	return 0;
}

int factorial(int n) {
	if (n > 0) {
		return n * factorial(n - 1);
	}
	else {
		return 1;
	}
}
int sum(int n, int *all) {
	int total = 0;
	for (int i = 0; i < n; ++i) {
		total += all[i];
	}
	return total;
}
int ave(int n, int *all) {
	int total = 0;
	for (int i = 0; i<n; ++i) {
		total += all[i];
	}
	return total / n;
}
int min(int n, int *all) {
	int min = all[0];
	for (int i = 1; i < n; ++i) {
		if (min > all[i]) {
			min = all[i];
		}
	}
	return min;
}
int max(int n, int *all) {
	int max = all[0];
	for (int i = 1; i<n; ++i) {
		if (max<all[i]) {
			max = all[i];
		}
	}
	return max;
}
int max(int n, int m) {
	if (n >= m) {
		return n;
	}
	else {
		return m;
	}
}
int min(int n, int m) {
	if (n >= m) {
		return m;
	}
	else {
		return n;
	}
}
