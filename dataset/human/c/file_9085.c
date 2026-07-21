#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void){
  long i;
  long N;
  int K;
  long ans=0;
  int h;
  scanf("%ld %d",&N,&K);
  // int h[N];

  for(i=0; i<N; i++){
    scanf("%d",&h);
    if(h>=K){
      ans++;
    }
  }

  printf("%ld\n", ans);

  return 0;
}
