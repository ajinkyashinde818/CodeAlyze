#include <stdio.h>

int main(void)
{
  int N, K;
  char dummy;

  scanf("%d%c", &N, &dummy);

  char S[N+1];

  scanf("%s", S);
  scanf("%d", &K);

  char tmp = S[K-1];

  for (int i=0;i<N;i++){
    if (S[i] != tmp){
      S[i] = '*';
    }
  }

  printf("%s\n", S);

  return 0;
}
