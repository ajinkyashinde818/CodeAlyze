#include <stdio.h>

int H, W, K;
char s[512][512];

int answer[512][512];

int main(void) {
	int i, j;
	int next = 0;
	if (scanf("%d%d%d", &H, &W, &K) != 3) return 1;
	for (i = 0; i < H; i++) {
		if (scanf("%511s", s[i]) != 1) return 1;
	}
	for (i = 0; i < H; i++) {
		int exists = 0;
		for (j = 0; j < W; j++) {
			exists = exists || (s[i][j] == '#');
		}
		if (exists) {
			int first = -1;
			for (j = 0; j < W; j++) {
				if (s[i][j] == '#') {
					if (first < 0) first = j;
					next++;
				}
				answer[i][j] = next;
			}
			for (j = 0; j < first; j++) {
				answer[i][j] = answer[i][first];
			}
		}
	}
	for (i = 1; i < H; i++) {
		for (j = 0; j < W; j++) {
			if (answer[i][j] == 0) answer[i][j] = answer[i - 1][j];
		}
	}
	for (i = H - 2; i >= 0; i--) {
		for (j = 0; j < W; j++) {
			if (answer[i][j] == 0) answer[i][j] = answer[i + 1][j];
		}
	}
	for (i = 0; i < H; i++) {
		printf("%d", answer[i][0]);
		for (j = 1; j < W; j++) printf(" %d", answer[i][j]);
		putchar('\n');
	}
	return 0;
}
