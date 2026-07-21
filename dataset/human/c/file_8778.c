#include <stdio.h>
typedef long long ll;

int main(void) {
  int i, j, k, sa = 1, h, w;
  scanf("%d%d", &h, &w);
  char s[h][w + 10];
  for(i = 0; i < h; ++i) scanf("%s", s[i]);
  for(i = 0; i < h; ++i) {
    for(j = 0; j < w; ++j) if(s[i][j] == '#') {
      int tmp = 1;
      if(i && s[i - 1][j] == '#') tmp = 0;
      if(j && s[i][j - 1] == '#') tmp = 0;
      if(i != h - 1 && s[i + 1][j] == '#') tmp = 0;
      if(j != w - 1 && s[i][j + 1] == '#') tmp = 0;
      if(tmp) sa = 0;
    }
    if(!sa) break;
  }
  if(sa) printf("Yes");
  else printf("No");
  return 0;
}
