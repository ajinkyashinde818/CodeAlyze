#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma warning( disable:4996 )
#define SWAP(a,b) (a += b,b = a - b,a -= b)
int main() {

	int r, g, b, N, R, G, B;
	int count = 0;
	scanf("%d %d %d %d", &R, &G, &B, &N);
	if (R < G) {
		SWAP(R, G);
	}
	if (G < B) {
		SWAP(G, B);
		if (R < G) {
			SWAP(R, G);
		}
	}
	for (r = N / R; r >= 0; r--) {
		int rest = N - r * R;
		for (g = rest / G; g >= 0; g--) {
			int rest2 = rest - g * G;
			if (rest2%B == 0)count++;
		}
	}

	printf("%d\n", count);
	return 0;
}
