#include <stdio.h>

int main( ) {
	int n;
	int R[200000];
	int i;
	int min;
	int score;
	int buff;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &R[i]);

	min = R[0];
	score = R[1] - R[0];

	for (i = 1; i < n; i++) {
		score = (score < (R[i] - min)) ? R[i] - min : score;
		if (min > R[i]) min = R[i];
	}

	printf("%d\n", score);

	return 0;
}
