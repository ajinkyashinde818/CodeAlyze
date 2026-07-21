#include <stdio.h>

int main(void) {
  int H,W,i,j,ans = 1;
  char S[51][51];
  scanf("%d %d",&H,&W);
  for (i = 0;i < H;i++) {
    scanf("%s",&S[i][0]);
  }
  for (i = 0;i < H;i++) {
    for (j = 0;j < W;j++) {
      if (S[i][j] == '#' && S[i - 1][j] != '#' && S[i][j - 1] != '#' && S[i][j + 1] != '#' && S[i + 1][j] != '#') ans = 0;
    }
  }
  if (ans == 1) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}
