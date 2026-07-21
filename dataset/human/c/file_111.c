#include <stdio.h>
#include <stdlib.h>

int main()
{
	int R, G, B, N;
	scanf("%d %d %d %d", &R, &G, &B, &N);
	
	int r, g, count = 0;
	for (r = 0; r <= N; r += R) {
		for (g = 0; g <= N - r; g += G) {
			if ((N - r - g) % B == 0) count++;
		}
	}
	
	printf("%d\n", count);
	fflush(stdout);
	return 0;
}
