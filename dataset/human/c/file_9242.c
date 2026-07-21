#include <stdio.h>

int main(){

  int i;
  int N;
  int K;
  int count;

  scanf("%d %d", &N, &K);
  int h[N];

  for(i = 1; i <= N; i++){

    scanf("%d", &h[i - 1]);
  }

  count = 0;

  for(i = 1; i <= N; i++){

    if(h[i - 1] >= K){
      count = count + 1;
    }
  }

  printf("%d", count);

  return 0;
}
