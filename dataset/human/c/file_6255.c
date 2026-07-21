#include <stdio.h>

int main(void)
{
	int num, i, a, b, min = 0, max;

	scanf("%d", &num);

	scanf("%d", &a);
	scanf("%d", &b);
	max = b - a;

	if (a < b) {
		min = a;
	}
	else {
		min = b;
	}

	for (i = 0; i < num - 2; i++) {
		scanf("%d", &a);

		if (a - min > max) {
			max = a - min;
		}

		if (min > a) {
			min = a;
		}
	}

	printf("%d\n", max);

	return 0;	
}
