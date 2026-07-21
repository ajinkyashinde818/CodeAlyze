#include <stdio.h>

int main(void){
  int H,W;
  scanf("%d%d",&H,&W);

  char S[H][W+1];
  for (int i = 0; i < H; i++) {
    scanf("%s",S[i]);
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if(S[i][j] == '.') continue;
      if(j != 0) if(S[i][j-1] == '#') continue;
      if(i != 0) if(S[i-1][j] == '#') continue;
      if(j != W-1) if(S[i][j+1] =='#') continue;
      if(i != W-1) if(S[i+1][j] =='#') continue;

      printf("No\n");
      return 0;
    }
  }

  printf("Yes\n");

  return 0;
}
