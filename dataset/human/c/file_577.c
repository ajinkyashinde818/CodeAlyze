#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <map>
#include <math.h>
#pragma warning(disable : 4996)

#define MAX_N 50

char A[MAX_N][MAX_N+1];
char B[MAX_N][MAX_N+1];

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		scanf("%s", &A[i]);
	}
	for (int i = 0; i < M; ++i) {
		scanf("%s", &B[i]);
	}
	for (int oy = 0; oy <= N - M; ++oy) {
		for (int ox = 0; ox <= N - M; ++ox) {
			bool match = true;
			for (int y = 0; y < M; ++y) {
				for (int x = 0; x < M; ++x) {
					if (A[oy + y][ox + x] != B[y][x]) {
						match = false;
						goto NOT_MATCH;
					}
				}
			}
		NOT_MATCH:
			if (match == true) {
				printf("Yes");
				return 0;
			}
		}
	}
	printf("No");
	return 0;
}
