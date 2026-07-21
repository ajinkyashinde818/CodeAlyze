#include <stdio.h>

int main()
{
  int N,D,X;
  scanf("%d%d%d",&N,&D,&X);
  int A[N];
  int i,k;
  int sum;
  sum = X;
  i = 0;
  while (i < N)
  {
    scanf("%d",&A[i]);
    k = 0;
    while (1 + k*A[i] <= D)
    {
      //printf("sum:%d A[i]:%d\n",sum,A[i]);
      sum++;
      k++;
    }
    i++;
  }
  printf("%d",sum);
}
