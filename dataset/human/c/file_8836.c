#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 52

struct point {
  int x;
  int y;
};

struct point dict[4] = {
  {-1, 0}, {1, 0},
  {0, -1}, {0, 1},
};

int main(void) {
  FILE *fp = stdin;
  char line[BUF_SIZE];

  if(!fgets(line, BUF_SIZE, fp)) return 0;
  int row, col;
  sscanf(line, "%d %d", &row, &col);



  int i, j, k;
  char map[BUF_SIZE][BUF_SIZE];
  for(i = 0; i < BUF_SIZE; i++) {
    for(j = 0; j < BUF_SIZE; j++) {
      map[i][j] = 0;
    }
  }
  for(i = 1; i <= row; i++) {
    if(!fgets(line, BUF_SIZE, fp)) return 0;
    char *buf;
    int s;
    for(buf = line, s = 1; *buf != '\n'; buf++, s++) {
      map[i][s] = (*buf == '#');
    }
  }

  for(i = 1; i <= row; i++) {
    for(j = 1; j <= col; j++) {
      if(!map[i][j]) continue;
      int flag = 0;
      for(k = 0; k < 4; k++) {
        flag |= map[i+dict[k].x][j+dict[k].y];
      }
      if(!flag) {
        printf("No\n");
        return 0;
      }
    }
  }
  printf("Yes\n");

  return 0;
}
