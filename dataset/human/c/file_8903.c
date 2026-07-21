#include <stdio.h>

int main(void) {

  int h,w;
  scanf("%d %d", &h, &w);
  char s[h][w+1];
  for (int i = 0; i < h; i++) {
    scanf("%s", s[i]);
  }
  int flag;
  int achieve = 1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        flag = 0;
        if (i > 0 && s[i-1][j] == '#') {
          flag = 1;
        }
        if (i < h-1 && s[i+1][j] == '#') {
          flag = 1;
        }
        if (j > 0 && s[i][j-1] == '#') {
          flag = 1;
        }
        if (j < w-1 && s[i][j+1] == '#') {
          flag = 1;
        }
        if (flag == 0) {
          achieve = 0;
          break;
        }
      }
    }
    if (achieve == 0) {
      break;
    }
  }
  if (achieve == 1) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
