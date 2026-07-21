#include<stdio.h>
#define MX 1099
int map[MX][MX], cnt, way[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, {0, -1} };
char s[MX];
int bfs[MX*MX][2];
int main() {
	int h, w, c[2], d[2], i, j, z;
	scanf("%d%d", &h, &w);
	for (i = 0; i < 2; i++) {
		scanf("%d", &c[i]);
		++c[i];
	}
	for (i = 0; i < 2; i++) {
		scanf("%d", &d[i]);
		++d[i];
	}
	for (i = 0; i <= (h + 3); i++) {
		for (j = 0; j <= (w + 3); j++) {
			if (2 <= i && i <= (h + 1) && 2 <= j && j <= (w + 1)) {
				map[i][j] = 0;
			}
			else {
				map[i][j] = -1;
			}
		}
	}
	for (i = 1; i <= h; i++) {
		scanf("%s", &s[1]);
		for (j = 1; j <= w; j++) {
			if (s[j] == '#') {
				map[i + 1][j + 1] = -1;
			}
			else {
				map[i + 1][j + 1] = 0;
			}
		}
	}
	int st = 1, ed = 1;
	bfs[1][0] = c[0], bfs[1][1] = c[1];
	map[c[0]][c[1]] = 1;
	for (int numb = 1;; ++numb) {
		for (i = st; i <= ed; i++) {
			for (j = 0; j < 4; j++) {
				if (map[bfs[i][0] + way[j][0]][bfs[i][1] + way[j][1]] == 0) {
					map[bfs[i][0] + way[j][0]][bfs[i][1] + way[j][1]] = numb;
					++ed;
					bfs[ed][0] = bfs[i][0] + way[j][0];
					bfs[ed][1] = bfs[i][1] + way[j][1];
				}
			}
		}
		int md = ed;
		for (i = st; i <= md; i++) {
			for (j = -2; j <= 2; j++) {
				for (z = -2; z <= 2; z++) {
					if (map[bfs[i][0] + j][bfs[i][1] + z] == 0) {
						map[bfs[i][0] + j][bfs[i][1] + z] = numb + 1;
						++ed;
						bfs[ed][0] = bfs[i][0] + j;
						bfs[ed][1] = bfs[i][1] + z;
					}
				}
			}
		}
		if (md == ed) {
			break;
		}
		st = md + 1;
	}
	printf("%d", map[d[0]][d[1]] - 1);
}
