#include <stdio.h>

#define MAX_SIZE 2000000

int main() {
	int n;
	scanf("%d", &n);

	int V[MAX_SIZE];
	int i;
	for (i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		V[i] = tmp;
	}

	int max_value = -999999999;

	int min_value = V[0];
	for (i = 1; i < n; i++) {
		if (max_value < (V[i] - min_value)) {
			max_value = V[i] - min_value;
		}
		if (min_value > V[i]) {
			min_value = V[i];
		}
	}

	printf("%d\n", max_value);
	return 0;
}
