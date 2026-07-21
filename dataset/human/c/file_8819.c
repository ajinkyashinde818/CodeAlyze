#include <stdio.h>

#define TRUE 0
#define FALSE -1

int check(char map[64][64], int i, int j, int up, int left, int down, int right) {
  int flg = FALSE;

  if(!up) {
    if(map[i-1][j] == '#') {
      flg = TRUE;
    }
  }
  if(!down) {
    if(map[i+1][j] == '#') {
      flg = TRUE;
    }
  }
  if(!left) {
    if(map[i][j-1] == '#') {
      flg = TRUE;
    }
  }
  if(!right) {
    if(map[i][j+1] == '#') {
      flg = TRUE;
    }
  }

  return flg;
}

int main(void) {
  int i, j;
  int flg = TRUE;
  int h, w;
  char s[64][64];
  scanf("%d %d", &h, &w);
  for(i = 0; i < h; i++) {
    scanf("%s", s[i]);
  }

  for(i = 0; i < h; i++) {
    for(j = 0; j < w; j++) {
      if(s[i][j] == '#' && check(s, i, j, i==0,j==0,i==h-1,j==w-1) == FALSE) {
        flg = FALSE;
        break;
      }
    }
  }

  if(flg == TRUE) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
