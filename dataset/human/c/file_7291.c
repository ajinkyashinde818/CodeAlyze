#include<stdio.h>
int H, W, K;
char cake[999][999];
int ans[999][999];
int main(int argc, char const *argv[]) {
  scanf("%d %d %d", &H, &W, &K);
  if (getchar() != '\n') return 1;
  for (int i = 0; i < H; i++) {
    fgets(cake[i], W+2, stdin); // W chars + newline + '\0'
  }
  int gen = 0, firstrow = 0, row = -1;
  for (int i = 0; i < H; i++) {
    int has = 0, firstcol = 0;
    for (int j = 0; j < W; j++) {
      if (cake[i][j] == '#') {
        if (has == 0) firstcol = j;
        has = ++gen;
      }
      ans[i][j] = has;
    }
    if (has != 0) {
      if (row == -1) firstrow = i;
      row = i;
      // fix first
      for (int j = 0; j < firstcol; j++) {
        ans[i][j] = ans[i][firstcol];
      }
    }
    else if (row != -1) {
      for (int j = 0; j < W; j++) {
        ans[i][j] = ans[row][j];
      }
    }
  }
  // first empty row
  for (int i = 0; i < firstrow; i++) {
    for (int j = 0; j < W; j++) {
      ans[i][j] = ans[firstrow][j];
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (j) putchar(' ');
      printf("%d", ans[i][j]);
    }
    putchar('\n');
  }
  return 0;
}
