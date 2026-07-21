#include <stdio.h>

#define MIN(A, B) (A) > (B) ? (B) : (A)
#define MAX(A, B) (A) > (B) ? (A) : (B)

int main() {
	int max_of_R;
	scanf("%d\n", &max_of_R);
	int R[max_of_R];
	for (int i = 0; i < max_of_R; i++) {
		scanf("%d\n", &R[i]);
	}

	int maxv = -0x80000000;
	int minv = R[0];
	for (int i = 1; i < max_of_R; i++) {
		maxv = MAX(maxv, R[i] - minv);
		minv = MIN(minv, R[i]);
	}

	printf("%d\n", maxv);

	return 0;
}
