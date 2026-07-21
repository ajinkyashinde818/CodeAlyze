#include<stdio.h>
#include<string.h>

int a[100001][2];


int main(void) {

	int n;
	int i, j;
	int flag = 1;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i][0]);
		a[i][1] = 1;
	}

	//ループのiに数列の値を代入してみる//
	j = 0;
	for (i = 0; i < n; i = a[i][0] - 1) {
		if (a[i][0] == 1) {
			printf("-1\n");
			return 0;
		}
		if (a[i][0] == 2) {
			printf("%d", j+1);
			return 0;
		}
		if (a[i][1] == 0) {
			printf("-1\n");
			return 0;
		}
		a[i][1] = 0;
		j++;
	}

	printf("-1\n");
	return 0;
}
