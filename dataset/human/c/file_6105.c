#include <stdio.h>
#include <math.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {

	int i;
	int num;
	int value;

	int min_value = 1000000000;
	int profit = 1 - 1000000000;

	scanf("%d", &num);

	for (i = 0; i < num; i++) {

		scanf("%d", &value);

		if (i == 0) {
			min_value = value;
		}
		else {

			profit = max(profit, value - min_value);
			min_value = min(min_value, value);
		}
	}


	printf("%d\n", profit);

	return 0;
}
