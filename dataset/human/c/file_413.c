#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

int main(void) {
	int n, r;

	scanf("%d %d", &n, &r);
	if (n >= 10) printf("%d", r);
	else printf("%d", r + 100 * (10 - n));
	return 0;
}
