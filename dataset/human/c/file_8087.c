#include <stdio.h>

int main(void)
{
  long long int a,b,c,d;

  scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
  if(a*b<c*d)
  {
    printf("%lld\n",c*d);
  }
  else
  {
    printf("%lld\n",a*b);
  }
  return 0;

}
