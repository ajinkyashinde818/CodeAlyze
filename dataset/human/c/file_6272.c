#include <stdio.h>
#include <math.h>

#define MAX 200000

int main(void) {
	int R[MAX];
	int i;
	int n;
	int min;
	int max = -2000000000;
		
	
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {
		scanf("%d", &R[i]);
	}
	
	min = R[0];
	
	for (i = 1; i < n; i++) {
		max = fmax(max, R[i] - min);
		min = fmin(min, R[i]);
	}

	printf("%d\n", max);

	return 0;
}
