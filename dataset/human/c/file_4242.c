#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#pragma warning( disable:4996 )
#define SWAP(a,b) (a += b,b = a - b,a -= b)
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int a[100001];
int n, m;

int compare(const void *a, const void *b) {
	int an = *(int*)(a);
	int bn = *(int*)(b);
	if (an < bn) {
		return -1;
	}
	else if (an > bn) {
		return 1;

	}
	else {
		return 0;
	}
}

int inarray(int x) {
	void* ans = NULL;
	ans = bsearch(&x, a, m, sizeof(int), compare);
	if (ans != NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

int main(void) {
	/*int p, q, r;
	scanf("%d %d %d", &p, &q, &r);
	int a, b, c;
	a = p + q;
	b = q + r;
	c = r + p;
	printf("%d\n", MIN(a, MIN(b, c)));*/
	/*
	int n;
	int w[101];
	scanf("%d", &n);
	scanf("%d", &w[0]);
	int first = w[0];
	int last = 0;
	for (int i = 1; i < n; i++) {
		scanf("%d", &w[i]);
		last += w[i];
	}

	int min = abs(first - last);
	for (int i = 1; i < n-1; i++) {
		first += w[i];
		last -= w[i];
		int temp = abs(first - last);
		if (min > temp) {
			min = temp;
		}
	}
	printf("%d\n", min);*/

	scanf("%d %d", &n, &m);
	long long int dp[100001];
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	if (inarray(0)) {
		dp[0] = 0;
	}
	else {
		dp[0] = 1;
	}
	if (inarray(1)) {
		dp[1] = 0;
	}
	else {
		dp[1] = 1 + dp[0];
	}
	for (int i = 2; i < n; i++) {
		if (inarray(i)) {
			dp[i] = 0;
		}
		else {
			dp[i] = (dp[i - 1] + dp[i - 2])%1000000007;
		}
	}
	printf("%lld\n", dp[n - 1]);
	return 0;
}
