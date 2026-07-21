#include <stdio.h>
int main(void)
{
  int A, B;
  scanf("%d %d", &A, &B);
  long c;
  int po;
  c = (long)A * B;

  if (A < B)
  {
    po = A;
    A = B;
    B = po;
  }
  int d = A % B;
  while (d != 0)
  {
    A = B;
    B = d;
    d = A % B;
  }
  printf("%ld", (long)(c / B));
  return 0;
}
