#include <stdio.h>
int main()
{
   long long int A,B,K,D=0,j;
  scanf("%lld%lld%lld",&A,&B,&K);
  for(long long int i=A;D!=K;i--)
  {
    if(A%i==0 && B%i==0) D++;
    j=i;
  }
  printf("%lld",j);
  return 0;
}
