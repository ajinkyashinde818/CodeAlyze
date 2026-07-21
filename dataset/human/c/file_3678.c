#include <stdio.h>
long long int pavan(long long int a,long long int b)
{
  if(a==0)
  {
    return b;
  }
  if(b==0)
  {
    return a;
  }
  pavan(b%a,a);
}
long long int main()
{
  long long int a,b;
  scanf("%lld %lld",&a,&b);
  printf("%lld\n",(a*b)/(pavan(a,b)));
  return 0;
}
