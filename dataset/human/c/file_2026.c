#include <stdio.h>

int main() {
	int A, B, C, min, max = 0;
	if (scanf("%d %d %d", &A, &B, &C) == -1) return -1;
	if (B >= C) max = B + C;
	else if (A >= C - B) max = B + C;
	else max = 2 * B + A + 1;
	printf("%d\n", max);
	return 0;
}
