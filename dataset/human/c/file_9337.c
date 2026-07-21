#include <stdio.h>
#include <string.h>
#include "math.h"


int main(int argc, char *argv[]){

  int i;
  int N, K;
  int l = 0;

  scanf("%d %d", &N, &K);

  int h[N];

  for(i=0; i<=N-1; i++){
    scanf("%d ", &h[i]);
  }

  for(i=0; i<=N-1; i++){
    if(h[i] >= K){
      l++;
    }
  }

  printf("%d\n", l);

  return 0;
}
