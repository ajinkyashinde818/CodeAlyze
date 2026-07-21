// Aizu 1193: Chain Disappearance Puzzle
// 2017.9.14 bal4u@uu

#include <stdio.h>

char map[12][6];

int main()
{
	int h, r, c, r2, c2, t, f, ans;

	while (scanf("%d", &h) && h) {
		for (r = 1; r <= h; r++) for (c = 1; c <= 5; c++) scanf("%d", &t), map[r][c] = t;
		ans = 0, f = 1; while (1) {
			for (f = 0, r = 1; r <= h; r++) for (c = 1; c <= 3; c++) {
				if (!map[r][c]) continue;
				for (t = 1, c2 = c+1; c2 <= 5; c2++, t++)
					if (map[r][c2] != map[r][c]) break;
				if (t >= 3) {
					ans += t * map[r][c], f = 1;
					for (c2 = c; t--; c2++) map[r][c2] = 0;
					c = c2-1;
				}
			}
			if (!f) break;
			for (r = h; r >= 1; r--) for (c = 1; c <= 5; c++) if (map[r][c] == 0) {
				for (r2 = r-1; r2 >= 1; r2--) if (map[r2][c]) break;
				for (t = r; t >= 1; t--, r2--)
					if (r2 < 1) map[t][c] = 0; else map[t][c] = map[r2][c];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
