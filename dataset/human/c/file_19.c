#include <stdio.h>
#include <algorithm>

#define LIM_S 200002
#define LIM_N 200001

char str[LIM_S];

int R, G, B, N;
int A[LIM_N];

void receive_input() {
	fgets(str, sizeof(str), stdin);
	sscanf(str, "%d %d %d %d", &R, &G, &B, &N);
}

void initialize() {
}

int main(void) {
	receive_input();
	initialize();

	int r, g, b;
	int ans = 0;

	for (r = N/R; 0 <= r; r--) {
		for (g = N/G; 0 <= g; g--) {
			int x = N - (r*R+g*G);
			int b = x / B;
			if (x >= 0 && x % B == 0) {
				// printf("%d %d %d :%d\n", r, g, b, x);
				ans++;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}
