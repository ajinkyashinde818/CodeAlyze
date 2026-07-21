#include <stdio.h>

void Do(int N){
  int i, K;
  char S[N];
  scanf("%s", S);
  scanf("%d", &K);
  for(i = 0;i < N;i++) if(S[i] != S[K-1]) S[i] = '*';
  printf("%s\n", S);
}

int main(void){
  int N;
  scanf("%d", &N);
  Do(N);
  return 0;
}
