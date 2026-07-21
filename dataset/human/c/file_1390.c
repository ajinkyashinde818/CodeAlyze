#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define Rep(i,a,n)for(int i=(int)(a);i<(int)(n);i++)
#define rep(i,n)Rep(i,0,n)
typedef long long ll;
typedef long double ld;

int sort1(const void* a, const void* b) {
	return *(int*)b - *(int*)a;
}

int main() {
	int n, m, a[200001], b[200001], c[200001] = { 0 }, d[200001] = { 0 };
	scanf("%d %d", &n, &m);
	rep(i, m) {
		scanf("%d %d", &a[i], &b[i]);
		if (a[i] == 1)c[b[i]] = 1;
		if (b[i] == n)d[a[i]] = 1;
	}
	rep(i, n) {
		if (c[i] == d[i] && c[i] == 1) { printf("POSSIBLE"); return 0; }
	}
	printf("IMPOSSIBLE");
}
