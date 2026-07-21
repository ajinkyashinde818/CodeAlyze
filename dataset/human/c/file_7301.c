#include <stdio.h>

int main(void){

  int h,w,k;
  scanf("%d %d %d", &h, &w, &k);
  char s[h][w+1];
  for (int i = 0; i < h; i++) {
    scanf("%s", s[i]);
  }
  int cut[h][w];
  int row[h];
  int strawberry;
  int area = 1;
  for (int i = 0; i < h; i++) {
    strawberry = 0;
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        strawberry++;
      }
    }
    row[i] = strawberry;
  }
  int start_row;
  int start_column;
  for (int i = 0; i < h; i++) {
    if (row[i] != 0) {
      start_row = i;
      for (int j = 0; j < w; j++) {
        if (s[i][j] == '#') {
          start_column = j;
          cut[i][j] = area;
          for (int l = 0; l < j; l++) {
            cut[i][l] = area;
          }
          break;
        }
      }
      for (int j = start_column+1; j < w; j++) {
        if (s[i][j] == '#') {
          area++;
        }
        cut[i][j] = area;
      }
      break;
    }
  }
  for (int i = 0; i < start_row; i++) {
    for (int j = 0; j < w; j++) {
      cut[i][j] = cut[start_row][j];
    }
  }
  for (int i = start_row+1; i < h; i++) {
    if (row[i] != 0) {
      area++;
      for (int j = 0; j < w; j++) {
        if (s[i][j] == '#') {
          start_column = j;
          cut[i][j] = area;
          for (int l = 0; l < j; l++) {
            cut[i][l] = area;
          }
          break;
        }
      }
      for (int j = start_column+1; j < w; j++) {
        if (s[i][j] == '#') {
          area++;
        }
        cut[i][j] = area;
      }
    } else {
      for (int j = 0; j < w; j++) {
        cut[i][j] = cut[i-1][j];
      }
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w-1; j++) {
      printf("%d ", cut[i][j]);
    }
    printf("%d\n", cut[i][w-1]);
  }

  return 0;
}
