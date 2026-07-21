#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  int N,K,C,i,j;
  int L[200000];
  int R[200000];
  char S[200000];
  scanf("%d %d %d",&N,&K,&C);
  scanf("%s",&S);

  j = 0;

  for(i=0;j<K;j++)
  {
    while(S[i] == 'x')
    {
      i++;
    }
    L[j] = i;
    i += C+1;
  }

  j = K-1;

  for(i=N-1;j>=0;j--)
  {
    while(S[i] == 'x')
    {
      i--;
    }
    R[j] = i;
    i -= C+1;
  }

  for(i=0;i<K;i++)
  {
    if(L[i] == R[i])
    {
      printf("%d\n",L[i]+1);
    }
  }

  return 0;
}
