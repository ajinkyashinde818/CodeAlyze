#include <stdio.h>
int main () {
  int h, w, i, j, x;
  char s[51][51];
  scanf ("%d%d", &h, &w);
  for (i = 0; i < h; ++i) {
    scanf ("%s", s[i]);
  }
  x = 1;
  for (i = 0; i < h && x == 1; ++i) {
    for (j = 0; j < w; ++j) {
      if (s[i][j] == '.') {
        continue;
      } else if (s[i-1][j] == '#' || s[i][j-1] == '#' || s[i][j+1] == '#' || s[\
i+1][j] == '#') {
        continue;
      } else {
        x = 0;
        break;
      }
    }
  }
  if (x == 1) {
    printf ("Yes\n");
  } else {
    printf ("No\n");
  }
  return 0;
}
