#include <stdio.h>

int main(){
  int R,G,B,N;
  int ans = 0;
  int r,g,b;
  scanf("%d %d %d %d",&R,&G,&B,&N);

  for(int i = 0; i <= N; i ++){
    for(int j = i; j <= N; j ++){
      r = i;
      g = j - i;
      b = N - j;
      if((r % R == 0) && (g % G == 0) && (b % B == 0)){
        ans ++;
      }
    }
  }

  printf("%d",ans);
  return 0;
}
