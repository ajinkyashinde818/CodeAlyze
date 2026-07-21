#include <stdio.h>

int Euclidean_algorithm(int A,int B)
{
  if (A >= B)
  {
    A = A % B;
    if (A == 0)
    {
      return (B);
    }
  }
  else
  {
    B = B % A;
    if (B == 0)
    {
      return (A);
    }
  }
  Euclidean_algorithm(A,B);
}

int main()
{
  int A,B;
  scanf("%d %d",&A,&B);
  printf("%ld",(long)A*B/Euclidean_algorithm(A,B));
}
