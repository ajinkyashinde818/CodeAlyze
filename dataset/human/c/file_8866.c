#include <stdio.h>

int H, W;
char map[50][50];

int paint(int h, int w) {
  if (h-1 >= 0) {
    if (map[h-1][w] == '#') return 1;
  }
  if (h+1 < H) {
    if (map[h+1][w] == '#') return 1;
  }
  if (w-1 >= 0) {
    if (map[h][w-1] == '#') return 1;
  }
  if (w+1 < W) {
    if (map[h][w+1] == '#') return 1;
  }
  return 0;
}

int main() {
  int i, j;
  
  scanf("%d %d", &H, &W);
  getchar();
  
  for (i = 0; i < H; i++) {
    for (j = 0; j < W; j++) {
      scanf("%c", &map[i][j]);
    }
    getchar();
  }
  
  for (i = 0; i < H; i++) {
    for (j = 0; j < W; j++) {
      if (map[i][j] == '#') {
	if (!paint(i, j)) {
	  printf("No\n");
	  return 0;
	}
      }
    }
  }

  printf("Yes\n");
  return 0;
}
