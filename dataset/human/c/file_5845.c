#include<stdio.h>
int main() {
	int n, i, j, r[200000], maxv, minv;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d", &r[i]);
	maxv = -2000000000;
	minv = r[0];
	for (j = 1; j < n; j++) {
		if (maxv < r[j] - minv)maxv = r[j] - minv;
		if (minv > r[j])minv = r[j];
	}
	printf("%d\n", maxv);
	return 0;
}
