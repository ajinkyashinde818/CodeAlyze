#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i, n, m;
	int answer = -1e9;
	int *input;

	scanf("%d", &n);
	input = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		scanf("%d", &input[i]);
	}

	m = input[0];

	for (i = 1; i < n; i++) {

		if (answer < (input[i] - m)) {
			answer = input[i] - m;
		}

		if (input[i] < m) {
			m = input[i];
		}

	}

	printf("%d\n", answer);

	free(input);

	return 0;
}
