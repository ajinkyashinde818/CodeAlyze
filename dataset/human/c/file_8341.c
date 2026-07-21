#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

char S[10+1];

int main()
{
  int cnt;
  int N,K;
  int i;

  cnt = scanf("%d", &N);
  scanf("%*c");
  for (i=1; i<=N; i++) {
    cnt = scanf("%c", &S[i]);
  }
  cnt = scanf("%d", &K);

  for (i=1; i<=N; i++) {
    if (S[i] != S[K]) {
      printf("*");
    } else {
      printf("%c", S[K]);
    }
  }

  return 0;
}
