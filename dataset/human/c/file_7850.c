// AOJ 0558: Cheese
// 2017.10.3 bal4u@uu

#include <stdio.h>
#include <ctype.h>

#define QMAX 2000000
typedef struct { int r, c, s; } Q;
Q q[2000005]; int top, end;
char map[1002][1002]; int h, w;
int sr[10], sc[10];
int mv[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int mk[1002][1002];

int bfs(int sr, int sc, int gr, int gc)
{
	int r, c, s, i, r2, c2;
	static int v = 0;

	mk[sr][sc] = ++v;
	q[0].r = sr, q[0].c = sc, q[0].s = 0, top = 0, end = 1;
	while (top < end) {
		r = q[top].r, c = q[top].c, s = q[top].s; if (++top == QMAX) top = 0;
		if (gr == r && gc == c) return s;
		for (i = 0; i < 4; i++) {
			r2 = r + mv[i][0], c2 = c + mv[i][1];
			if (r2 < 0 || r2 >= h || c2 < 0 || c2 >= w || map[r2][c2] == 'X') continue;
			if (mk[r2][c2] == v) continue;
			mk[r2][c2] = v;
			q[end].r = r2, q[end].c = c2, q[end].s = s+1; if (++end == QMAX) end = 0;
		}
	}
	return 0;
}

int main()
{
	int n, i, r, c, ans;
	char a;

	scanf("%d%d%d", &h, &w, &n);
	for (r = 0; r < h; r++) {
		scanf("%s", map[r]);
		for (c = 0; c < w; c++) {
			if (map[r][c] == 'S')
				sr[0] = r, sc[0] = c, map[r][c] = '.';
			else if (isdigit(a = map[r][c]))
				sr[a-'0'] = r, sc[a-'0'] = c, map[r][c] = '.';
		}
	}
	for (ans = 0, i = 0; i < n; i++) ans += bfs(sr[i], sc[i], sr[i+1], sc[i+1]);
	printf("%d\n", ans);
}
