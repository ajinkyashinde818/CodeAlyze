#include <stdio.h>

int main(){
  int N,K;
  int count=0;
  scanf("%d %d", &N, &K)+1;
  int tmp;
  for (int i=0; i<N; i++){
    scanf("%d", &tmp)+1;
    if (tmp >= K) count++;
  }
  printf("%d\n", count);
  return 0;
}
