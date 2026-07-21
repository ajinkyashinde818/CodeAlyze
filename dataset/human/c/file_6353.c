#include <stdio.h>

int main(void) {
	int n, max, min;
	int x[200000];
	int i, j;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}

	max = x[1] - x[0];
	min = x[0];

	if (n != 2) {
		for (i = 1; i < n; i++) {
			if (min > x[i]) {
				min = x[i];
			}
			else {
				if (max < x[i] - min) {
					max = x[i] - min;
				}
			}
			
		}
	}
	
	printf("%d\n", max);
	return 0;
}
