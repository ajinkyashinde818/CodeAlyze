#include <stdio.h>

void Tenka(int N) {
  char S[N];
  int K, i;
  scanf("%s%d",S,&K);
  for (i = 0; i < N; i++) {
    if (S[i] != S[K-1]) {
      S[i] = '*';
    }
  }
  printf("%s",S);
}

int main(void) {
  int N;
  scanf("%d",&N);
  Tenka(N);
  return 0;
}
