#include <stdio.h>
int main(void) {
	
	int x[10000];
	int i = 1, j = 1;

	while (1) {
		scanf("%d\n", &x[i]);
		if (1 <= x[i] && x[i] <= 10000) {
			if (x[i] == 0) break;
			i++;
		}
		else break;
	}

	while (1) {
		printf("Case %d: %d\n", j, x[j]);
		j++;
		if (j == i) break;
	}
	
	return 0;
}
