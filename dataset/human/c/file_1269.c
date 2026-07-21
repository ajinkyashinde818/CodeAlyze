// Aizu Vol-2 0210: The Squares
// 2017.9.11 bal4u@uu

#include <stdio.h>

#define W 1
#define S 2
#define E 3
#define N 4

typedef struct { int r, c, d; } MAN;
MAN man[1000]; int n, safe;
char map[33][33]; int w, h;
char tr['Z'];
int mov[5][4][3] = { { 0 },
	{ { -1, 0, N }, {  0,-1, W }, {  1, 0, S }, {  0, 1, E } },
	{ {  0,-1, W }, {  1, 0, S }, {  0, 1, E }, { -1, 0, N } },
	{ {  1, 0, S }, {  0, 1, E }, { -1, 0, N }, {  0,-1, W } },
	{ {  0, 1, E }, { -1, 0, N }, {  0,-1, W }, {  1, 0, S } },
 };

int main()
{
	int i, j, r, c, d, rr, cc, dd, t;

	tr['W'] = W, tr['S'] = S, tr['E'] = E, tr['N'] = N;
	while (scanf("%d%d", &w, &h) && w) {
		for (r = 0; r < h; r++) scanf("%s", map[r]);
		for (n = r = 0; r < h; r++) for (c = 0; c < w; c++) {
			int p = map[r][c];
			if (tr[p] > 0) man[n].r = r, man[n].c = c, man[n++].d = tr[p], map[r][c] = 'P';
		}
		for (safe = 0, t = 1; t <= 180; t++) {
			for (i = 0; i < n; i++) if (man[i].r >= 0) {
				r = man[i].r, c = man[i].c, d = man[i].d;
				for (j = 0; j < 4; j++) {
					rr = r + mov[d][j][0], cc = c + mov[d][j][1];
					if (rr < 0 || rr >= h || cc < 0 || cc >= w) continue;
					if (map[rr][cc] == '.' || map[rr][cc] == 'X') {	man[i].d = mov[d][j][2]; break;	}
				}
			}
			for (dd = 1; dd <= 4; dd++) for (i = 0; i < n; i++) if (man[i].r >= 0) {
				if ((d = man[i].d) == dd) {
					r = man[i].r, c = man[i].c;
					rr = r + mov[d][1][0], cc = c + mov[d][1][1];
					if (rr < 0 || rr >= h || cc < 0 || cc >= w) continue;
					if (map[rr][cc] == 'X') {
						map[r][c] = 'p', man[i].r = -1, map[rr][cc] = 'x'; 
						if (++safe == n) { printf("%d\n", t); goto Done; }
					} else if (map[rr][cc] == '.') {
						map[r][c] = 'p', man[i].r = rr, man[i].c = cc, map[rr][cc] = 'P';
					}
				}
			}
			for (r = 0; r < h; r++) for (c = 0; c < w; c++) {
				if      (map[r][c] == 'x') map[r][c] = 'X';
				else if (map[r][c] == 'p') map[r][c] = '.';
			}
//			for (r = 0; r < h; r++) puts(map[r]);putchar('\n');
		}
		puts("NA");
		Done:;
	}
	return 0;
}
