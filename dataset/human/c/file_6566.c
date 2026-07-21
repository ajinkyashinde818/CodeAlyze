#include <stdio.h>

int main(void)
{
	int n, i;
	int min, max;
	int r[200000];
	
	scanf("%d\n", &n);
	
	for (i = 0; i < n; i++) {
		scanf("%d\n", &r[i]);
	}
	
	max = -2000000000;
	min = r[0];
	
	for ( i = 1; i < n; i++) {
		if (r[i] - min > max) {
			max = r[i] - min;
		}
		
		if (r[i] < min) {
			min = r[i];
		}
	}
	
	printf("%d\n", max);
	return 0;
}
