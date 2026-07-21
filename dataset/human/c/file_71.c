#include <stdio.h>
int main(){
  int N;
  int R, G, B;
  scanf("%d%d%d%d", &R, &G, &B, &N);
  int r, g;
  long ans=0;
  for(r=0; r<=N/R; r++){
    for(g=0; g<=N/G; g++){
      int n = N-r*R-g*G;
      if(n>=0 && n%B==0) ans++;
    }
  }
  printf("%ld\n", ans);
}
