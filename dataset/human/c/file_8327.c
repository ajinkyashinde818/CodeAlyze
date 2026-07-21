#include <stdio.h>

int main(void)
{
  int N,N_c;
  scanf ("%d",&N);
  N_c=N;
  char S[N];
  scanf ("%s",S);
  int K;
  scanf ("%d",&K);
  char target = S[K-1];
  while (N_c)
  {
    if (S[N_c-1]!=target) S[N_c-1]='*';
    N_c--;
  }
  printf ("%s",S);
  return 0;
}
