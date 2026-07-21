//ITP1 - 2 - E
#include<stdio.h>
int main() {
	int i = 0, j, x[10000];

	while (10000) {
		scanf("%d", &x[i]);

		if (x[i] == 0) {
			break;
		}
		i++;
	}
	for (j = 1; j <= i; j++) {
		printf("Case %d: %d\n", j, x[j-1]);
	}

	return 0;
}
