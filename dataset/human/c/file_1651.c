#pragma warning (disable:4996)
#include<stdio.h>

int main(void) {
	int n;
	int a[20];
	int b[20];
	int c[19];
	int ans = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d", &c[i]);
	}

	for (int i = 0; i < n; ++i) {
		int j = a[i]-1;
		ans += b[j];
		if (a[i] - 1 == a[i - 1]) {
			ans += c[a[i] - 2];
		}
	}

	printf("%d\n", ans);
}
