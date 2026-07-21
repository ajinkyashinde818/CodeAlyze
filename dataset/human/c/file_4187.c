#include <stdio.h>
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

int main()
{
	int a, b, k;
	int div;
	int cnt = 0;

	scanf("%d %d %d", &a, &b, &k);

	for (div = min(a, b); div >= 1; div--) {
		if (a % div == 0 && b % div == 0) {
			cnt++;

			if (cnt == k) {
				printf("%d\n", div);

				return 0;
			}
		}
	}


	return 0;
}
