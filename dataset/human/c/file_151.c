#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	if (n == 1) {
		printf("Yes\n");
		printf("2\n");
		printf("1 1\n");
		printf("1 1\n");
		return 0;
	}
	int e = 0;
	for (int i = 2; i < 1000; i++) {
		if (i*(i + 1) / 2 == n)e = i;
	}
	if (e == 0) {
		printf("No\n");
		return 0;
	}
	e++;
	int a[1000][1000];
	int f = 1;
	for (int i = 0; i < e; i++) {
		for (int j = 0; j < e; j++) {
			if (i > j) {
				a[i][j] = f;
				f++;
			}
		}
	}
	for (int i = 0; i < e; i++) {
		for (int j = 0; j < e; j++) {
			if (j > i)a[i][j] = a[j][i];
		}
	}
	printf("Yes\n");
	printf("%d\n", e);
	for (int i = 0; i < e; i++) {
		printf("%d", e - 1);
		for (int j = 0; j < e; j++) {
			if (i != j) {
				printf(" %d", a[i][j]);
			}
		}
		printf("\n");
	}
}
