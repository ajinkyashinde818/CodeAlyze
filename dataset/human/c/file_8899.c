#include <stdio.h>

int H, W;
char s[64][64];

int main(void) {
	int i, j;
	if (scanf("%d%d", &H, &W) != 2) return 1;
	for (i = 1; i <= H; i++) {
		if (scanf("%63s", s[i] + 1) != 1) return 1;
	}
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= W; j++) {
			if (s[i][j] == '#' && s[i - 1][j] != '#' && s[i + 1][j] != '#' && s[i][j - 1] != '#' && s[i][j + 1] != '#') {
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
	return 0;
}
