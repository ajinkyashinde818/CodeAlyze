#include <stdio.h>
char a[81][81][160 * 160 + 1];
int c[81][81];
int h, w, x, y;
int ans = 160 * 160;
int main() {
	scanf("%d%d", &h, &w);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			scanf("%d", c[i] + j);
		}
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			scanf("%d", &x);
			c[i][j] -= x;
		}
	}
	for (int i = 0; i <= h; i++) {
		a[i][0][80 * 160] = 1;
	}
	for (int i = 0; i <= w; i++) {
		a[0][i][80 * 160] = 1;
	}
	for (int i = 2; i <= h + w; i++) {
		for (int j = 1; j < i; j++) {
			x = j;
			y = i - x;
			if (1 <= x && x <= h) {
				if (1 <= y && y <= w) {
					for (int k = 0; k <= 160 * 160; k++) {
						if (a[x - 1][y][k] && !(x == 1 && y != 1)) {
							a[x][y][k + c[x][y]] = 1;
							a[x][y][k - c[x][y]] = 1;
						}
						if (a[x][y - 1][k] && !(x != 1 && y == 1)) {
							a[x][y][k + c[x][y]] = 1;
							a[x][y][k - c[x][y]] = 1;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i <= 160 * 160; i++) {
		if (a[h][w][i]) {
			x = i - 160 * 80;
			if (x < 0)x = -x;
			if (x < ans)ans = x;
		}
	}
	printf("%d\n", ans);
}
