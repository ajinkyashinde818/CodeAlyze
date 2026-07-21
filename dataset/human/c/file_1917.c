#include<stdio.h>
int main(void) {
	int n;
	int st;
	int a[20];
	int b[20];
	int c[20];
	int i;
	st=0;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	for (i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}

	for (i = 1; i < n; i++) {
		if (a[i + 1] == a[i] + 1) {
			st = st + c[a[i]];
		}
	}
	for (i = 1; i <= n; i++) {
		st = st + b[i];
	}

	printf("%d", st);

	return 0;
}
