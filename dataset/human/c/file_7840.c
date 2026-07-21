#include <ctype.h>
#include <string.h>
#include <stdio.h>
#define N 1005

char G[N][N];
int row, col, n, dir[2][4], vis[N][N];

typedef struct { int r, c;} point;
point que[1000005], ps[10];

int in(point p) {
    return 0 <= p.r && p.r < row && 0 <= p.c && p.c < col;
}

int bfs(point s, point t) {
    int head = 0, tail = 1;
    for (int i = 0; i < row; ++i) memset(vis[i], -1, col * sizeof(int));
    vis[s.r][s.c] = 0;
    for (que[0] = s; head != tail;) {
        point p = que[head++];
        for (int i = 0; i < 4; ++i) {
            point near = {p.r + dir[0][i], p.c + dir[1][i]};
            if (in(near) && G[near.r][near.c] != 'X' && vis[near.r][near.c] < 0) {
                vis[near.r][near.c] = vis[p.r][p.c] + 1;
                if (near.r == t.r && near.c == t.c) return vis[near.r][near.c];
                que[tail++] = near;
            }
        }
    }
    return -1;
}

int solve(void) {
    int ans = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (isdigit(G[i][j])) ps[G[i][j] - '0'] = (point){i, j};
            else if (G[i][j] == 'S') ps[0] = (point){i, j};
        }
    }
    for (int i = 0; i < n - 1; ++i) ans += bfs(ps[i], ps[i+1]);
    return ans;
}

int main(void) {
    dir[0][0] = dir[1][2] = 1;
    dir[0][1] = dir[1][3] = -1;
    scanf("%d%d%d", &row, &col, &n); ++n;
    for (int i = 0; i < row; ++i) scanf("%s", G[i]);
    printf("%d\n", solve());
}
