#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int H, W;
  char **s;
  scanf("%d%d", &H, &W);
  s = (char**)malloc(sizeof(char*) * H);
  for (int i = 0; i < H; i++) {
    getchar();
    s[i] = (char*)malloc(sizeof(char) * W);
    for (int j = 0; j < W; j++) {
      scanf("%c", &s[i][j]);
    }
  }

  for (int j = 0; j < H; j++) {
    for (int i = 0; i < W; i++) {
      int cnt = 0;
      if (s[j][i] != '#') continue;
      if (i >= 1 && s[j][i-1] == '#') cnt++;
      if (j >= 1 && s[j-1][i] == '#') cnt++;
      if (i <= W-2 && s[j][i+1] == '#') cnt++;
      if (j <= H-2 && s[j+1][i] == '#') cnt++;
      if (cnt == 0) {
        puts("No");
        return 0;
      }
    }
  }
  puts("Yes");
  return 0;
}
