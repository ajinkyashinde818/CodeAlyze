#include <stdio.h>

int main() {
	int A, B, K, i, tmp;

	scanf("%d %d %d", &A, &B, &K);

	if (A > B) {
		tmp = A;
		A = B;
		B = tmp;
	}

	for (i = A; K > 0 && i > 0; i--) {
		if (A % i == 0 && B % i == 0) {
			K--;
		}
	}

	i++;

	printf("%d", i);

	return 0;
}
