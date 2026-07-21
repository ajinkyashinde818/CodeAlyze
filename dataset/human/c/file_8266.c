#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  int N, K, index;
  char S[10];
  char check;

  scanf("%d %s %d", &N, &S, &K);
  check = S[K-1];
  for (index < 0; index < N; ++index) {
    if (S[index] != check) S[index] = '*';
  }
  printf("%s\n", S);
  return 0;
}
