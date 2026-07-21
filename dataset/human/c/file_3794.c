#include <stdio.h>
int main(void)
{
  long int A,B,tmp;
  long int N=1;
  scanf("%ld %ld",&A,&B);
  if(A>=B) 
  {
    tmp = A;
    A = B;
    B = tmp;
  }
  
  while((A*N)%B != 0)
  {
    N++;
  }
  printf("%ld\n",A*N);
  return 0;  
}
