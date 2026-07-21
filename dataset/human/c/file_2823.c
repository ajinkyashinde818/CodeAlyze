#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int x, y, z;
	int K, S;
	int count = 0;

	scanf("%d %d", &K, &S);

	for (x = 0; x <= K; x++) {
		for (y = 0; y <= K; y++) {
			z = S - x - y;
			if (z >= 0 && z <= K) {
				count++;
			}
		}
	}
	printf("%d\n", count);

	return (0);
}
