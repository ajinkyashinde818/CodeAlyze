#include <stdio.h>
#include <limits.h>

int main(int argc, char** argv)
{
	int i, num;
	long  R[200000];

	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d", &R[i]);
	}

	long min_value = R[0];
	long max = LONG_MIN;

	for (i = 1; i < num; i++) {
		int val = R[i] - min_value;
		if (max < val) {
			max = val;
		}

		if (min_value > R[i]) {
			min_value = R[i];
		}
	}
	printf("%ld\n", max);
	return 0;
}
