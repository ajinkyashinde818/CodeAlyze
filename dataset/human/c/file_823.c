#include <stdio.h>
#define INF 1 << 29

int min(int a,int b){
  if(a < b){
    return a;
  }
  return b;
}

int main(void){
  int D,G;
  scanf("%d%d",&D,&G);

  int p[D],c[D];
  for (int i = 0; i < D; i++) {
    scanf("%d%d",&p[i],&c[i]);
  }

  int ans = INF;
  for (int i = 0; i < 1<<D; i++) {
    int maxnum = -1;
    int point = 0;
    int cnt = 0;
    for (int j = 0; j < D; j++) {
      if((i>>j)&1){
        point += (j+1)*100*p[j]+c[j];
        cnt += p[j];
      } else maxnum = j;
    }
    if(point >= G) ans = min(ans,cnt);
    else{
      if(maxnum == -1) continue;
      int plus = (G-point+(maxnum+1)*100-1)/((maxnum+1)*100);
      if(plus >= p[maxnum]) continue;
      ans = min(ans,cnt+plus);
    }
  }

  printf("%d\n",ans);

  return 0;
}
