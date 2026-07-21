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
	int W, H, N, X, Y;
	int x = 0, y = 0;
	int ans = 0;
	scanf("%d %d %d", &W, &H, &N);
	scanf("%d %d", &x, &y);
	for (int i = 2; i <= N; i++) {
		//printf("%d %d %d\n",x,y,ans);
		scanf("%d %d", &X, &Y);
		ans += abs(x - X);
		ans += abs(y - Y);
		if ((X > x && Y > y) | (X < x && Y < y)) {
			ans -= min(abs(x - X), abs(y - Y));
		}
		x = X;
		y = Y;
		
	}
	printf("%d\n", ans);
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
		if (all[0] > all[i]) {
			min = all[i];
		}
	}
	return min;
}
int max(int n, int *all) {
	int max = all[0];
	for (int i = 1; i<n; ++i) {
		if (all[0]<all[i]) {
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
