#include <stdio.h>
#define QUEUE_SIZE 1000003
#define MAXN 10
#define MAXH 1001
#define MAXW 1001
#define INF (1<<29)

int begin, end;
int queue_x[QUEUE_SIZE];
int queue_y[QUEUE_SIZE];

void init() {
  begin = end = 0;
}

void push(int x, int y) {
  queue_x[end] = x;
  queue_y[end] = y;
  ++end;
}

int getX() {
  return queue_x[begin];
}

int getY() {
  return queue_y[begin];
}

void pop() {
  ++begin;
}

int empty() {
  if(end - begin == 0) return 1;
  else return 0;
}

int H, W, N;
char G[MAXH][MAXW];
int cost[MAXH][MAXW];
int posX[MAXN], posY[MAXN];
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

int bfs(int sx, int sy, int ex, int ey) {
  int i, j, x, y, nx, ny;
  for(i = 0; i < H; ++i) {
    for(j = 0; j < W; ++j) {
      cost[i][j] = INF;
    }
  }
  init();
  push(sx, sy);
  cost[sy][sx] = 0;
  while(!empty()) {
    x = getX();
    y = getY();
    pop();
    for(i = 0; i < 4; ++i) {
      nx = x + dx[i];
      ny = y + dy[i];
      if(0 <= nx && nx < W &&
         0 <= ny && ny < H && G[ny][nx] != 'X' && cost[ny][nx] == INF) {
        push(nx, ny);
        cost[ny][nx] = cost[y][x] + 1;
        if(nx == ex && ny == ey) {
          return cost[ny][nx];
        }
      }
    }
  }
  return INF;
}

int main() {
  int i, j, k, x, y, ans;
  scanf("%d %d %d", &H, &W, &N);
  for(i = 0; i < H; ++i) {
    for(j = 0; j < W; ++j) {
      scanf(" %c", &G[i][j]);
      if(G[i][j] == 'S') {
        posX[0] = j;
        posY[0] = i;
      } else if('1' <= G[i][j] && G[i][j] <= '9') {
        posX[G[i][j] - '0'] = j;
        posY[G[i][j] - '0'] = i;
      }
    }
  }
  ans = 0;
  for(i = 0; i < N; ++i) {
    ans += bfs(posX[i], posY[i], posX[i+1], posY[i+1]);
  }
  printf("%d\n", ans);
  return 0;
}
