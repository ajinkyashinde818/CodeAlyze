#include <stdio.h>
#include <string.h>
int main(void) {
  int N,K;
  char S[11];
  scanf("%d",&N);
  scanf("%s",S);
  scanf("%d",&K);
  int i; /* index */
  for (i = 0;i < N;++i) {
    if(S[K - 1] != S[i]) {
      S[i] = '*';
    }
  }
  printf("%s\n", S);
  return 0;
}
