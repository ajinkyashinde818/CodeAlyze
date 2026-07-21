#include<stdio.h>

int main(void){

	int n, d[100][2];
	int i, k;

	scanf("%d", &n);
	for (k = 0; k <= n - 1;k++) {
		scanf("%d %d", &d[k][0], &d[k][1]);
	}

	for (i = 0;i <= n - 3;i++) {
		if (d[i][0] == d[i][1] && d[i + 1][0] == d[i + 1][1] && d[i + 2][0] == d[i + 2][1]) {
			printf("Yes");
			return 0;
		}
	}
	printf("No");
	return 0;
}
