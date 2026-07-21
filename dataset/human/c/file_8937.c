/* Coached by rainboy */
#include <stdio.h>

#define H 50
#define W 50

int main() {
	static char cc[H][W + 1];
	int h, w, i, j;

	scanf("%d%d", &h, &w);
	for (i = 0; i < h; i++)
		scanf("%s", cc[i]);
	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
			if (cc[i][j] == '#'
					&& (i + 1 == h || cc[i + 1][j] != '#')
					&& (j + 1 == w || cc[i][j + 1] != '#')
					&& (i == 0 || cc[i - 1][j] != '#')
					&& (j == 0 || cc[i][j - 1] != '#')) {
				printf("No\n");
				return 0;
			}
	printf("Yes\n");
	return 0;
}
