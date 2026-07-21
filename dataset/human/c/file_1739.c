#include <stdio.h>

int main(void)
{
	int n;
	int a[20], b[20], c[19];
	int i;
	int sum = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		sum += b[i];
	}

	for (i = 0; i < n - 1; i++) {
		scanf("%d", &c[i]);
	}

	for (i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1] - 1) {
			sum += c[a[i]-1];
		}
	}

	printf("%d\n", sum);

	return 0;
}
