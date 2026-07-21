#include <stdio.h>
#include <string.h>
#define HWMAX 1000
#define NMAX 9
int h, w, n;
char field[HWMAX][HWMAX];
int bfs(int sx, int sy, int gx, int gy);
int main(void)
{
  int i, j, ans = 0, plant[NMAX+1][2];
  scanf("%d %d %d%*c", &h, &w, &n);
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      field[i][j] = getchar_unlocked();
      if (field[i][j] == 'S') {
        plant[0][0] = i;
        plant[0][1] = j;
      } else if (field[i][j] >= '1' && field[i][j] <= '9') {
        plant[field[i][j]-'0'][0] = i;
        plant[field[i][j]-'0'][1] = j;
      }
    }
    getchar_unlocked();
  }
  for (i = 0; i < n; i++) ans += bfs(plant[i][0], plant[i][1], plant[i+1][0], plant[i+1][1]);
  printf("%d\n", ans);
}

int bfs(int sx, int sy, int gx, int gy)
{
  int top = 0, tail = 0, que[h*w][2], dist[h][w];
  memset(dist, -1, sizeof(dist));
  que[tail][0] = sx;
  que[tail++][1] = sy;
  dist[sx][sy] = 0;
  while (top != tail) {
    int d, px = que[top][0], py = que[top++][1], dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    if (px == gx && py == gy) return dist[px][py];
    for (d = 0; d < 4; d++) {
      int nx = px + dx[d], ny = py + dy[d];
      if (nx >= 0 && nx < h && ny >= 0 && ny < w && field[nx][ny] != 'X' && dist[nx][ny] == -1) {
        que[tail][0] = nx;
        que[tail++][1] = ny;
        dist[nx][ny] = dist[px][py] + 1;
      }
    }
  }
  return 0;
}
