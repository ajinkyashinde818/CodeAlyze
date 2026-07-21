// JOI13-quest3.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

int absolute(int *n) {

	if (*n >= 0) {
		return *n;
	}
	else {
		*n *= -1;
		return *n;
	}
}

int big(int n, int m) {
	int max;

	absolute(&n);
	absolute(&m);

	if (n >= m) {
		max = n;
	}
	else {
		max = m;
	}

	return max;
}

int main(void)
{
	int width, height, number;

	scanf("%d %d %d", &width, &height, &number);

	int x1, y1, x2, y2, minus_x, minus_y, sum = 0;
	scanf("%d %d", &x1, &y1);

	for (int i = 0; i < number - 1; i++) {
		scanf("%d %d", &x2, &y2);
		minus_x = x1 - x2;
		minus_y = y1 - y2;

		if ((minus_x > 0 && minus_y > 0) || (minus_x < 0 && minus_y < 0)) {
			sum += big(minus_x, minus_y);
		}
		else if (minus_x == 0) {
			absolute(&minus_y);
			sum += minus_y;
		}
		else if (minus_y == 0) {
			absolute(&minus_x);
			sum += minus_x;
		}
		else {
			absolute(&minus_x);
			absolute(&minus_y);
			sum += (minus_x + minus_y);
		}

		x1 = x2;
		y1 = y2;
	}

	printf("%d\n", sum);

	return 0;
}
