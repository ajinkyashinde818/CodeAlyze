#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIR_CNT 4
int next_dir4[DIR_CNT][2] = {
  {-1, 0},
  {0, -1},
  {0, 1},
  {1, 0},
};

void get_int3(char *line, int size, int *a1, int *a2, int *a3) {
  if(!fgets(line, size, stdin)) return;
  sscanf(line, "%d %d %d", a1, a2, a3);
}

#define LEN_MAX 1000
#define BUF_SIZE LEN_MAX+3
#define ROW_MAX (LEN_MAX+2)
#define COL_MAX (LEN_MAX+2)


struct point {
  int x;
  int y;
  int dist;
};

struct point stack[ROW_MAX*COL_MAX];
int start = 0;;
int end = 0;

int is_empty(void) {
  return start == end;
}

void enqueue(struct point p) {
  stack[start++] = p;
}

struct point dequeue(void) {
  return stack[end++];
}

int main(void) {
  char line[BUF_SIZE];
  int row, col, cheeses;
  get_int3(line, BUF_SIZE, &row, &col, &cheeses);

  char map[ROW_MAX][COL_MAX];
  char checked[ROW_MAX][COL_MAX];
  int i, j;
  for(i = 0; i < ROW_MAX; i++) {
    memset(map[i], 'X', COL_MAX);
  }
  struct point ps[10];
  for(i = 1; i <= row; i++) {
    if(!fgets(line, BUF_SIZE, stdin)) return 0;
    for(j = 1; j <= col; j++) {
      map[i][j] = line[j-1];
      if(map[i][j] == 'S') {
        ps[0].x = i; ps[0].y = j; ps[0].dist = 0;
      }
      if(map[i][j] >= '1' && map[i][j] <= '9') {
        int idx = map[i][j] - '0';
        ps[idx].x = i; ps[idx].y = j;
      }
    }
  }

  for(i = 1; i <= cheeses; i++) {
    for(j = 0; j < ROW_MAX; j++) memset(checked[j], 0, COL_MAX);
    start = end = 0; // initialize queue
    enqueue(ps[i-1]);
    checked[ps[i-1].x][ps[i-1].y] = 1;
    while(!is_empty()) {
      struct point p = dequeue();
      if(map[p.x][p.y] == (i+'0')) {
        ps[i].dist = p.dist;
        break;
      }
      int ndist = p.dist + 1;
      for(j = 0; j < DIR_CNT; j++) {
        int next_x = p.x + next_dir4[j][0];
        int next_y = p.y + next_dir4[j][1];
        if(checked[next_x][next_y]) continue;
        if(map[next_x][next_y]=='X') continue;
        struct point np = {next_x, next_y, ndist};
        enqueue(np);
        checked[next_x][next_y] = 1;
      }
    }
  }
  printf("%d\n", ps[cheeses].dist);

  return 0;
}
