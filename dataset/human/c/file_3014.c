#include<stdio.h>

int main(void) {
	int m, n=0,s=0;
	scanf("%d%d", &m, &n);
	int a[2*100000];

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	s = a[0] + m - a[n - 1];

	for (int i = 0; i < n - 1; i++) {
		if (a[i + 1] - a[i] > s) {
			s = a[i + 1] - a[i];
		}
	}
	printf("%d", m - s);
}
