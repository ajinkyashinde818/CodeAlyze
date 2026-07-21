#include <stdio.h>

int main(void) {
	int N;
	int *a;
	int i, check = -1, num = 2, x, ans = 0;
	int *c;

	scanf("%d", &N);
	a = (int*)malloc(sizeof(int)*N);
	c = (int*)malloc(sizeof(int)*N);
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 2) check = 1;
		c[i] = 0;
	}
	if (check!=1) {
		printf("%d\n", check);
		return 0;
	}
	i = 0;
	while (c[i] == 0) {
		num = a[i];
		c[i] = 1;
		i = num - 1;
		ans++;
		if (num == 2) {
			printf("%d\n", ans);
			return 0;
		}
	}
	printf("-1\n");

	return 0;
}
