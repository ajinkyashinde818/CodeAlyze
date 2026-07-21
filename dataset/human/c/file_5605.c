#include<stdio.h>
int main(void)
{
  long long int x,ans,kaisuu;

  scanf("%lld",&x);

  ans=x/11;

  if(x%11>=7){
    kaisuu=ans*2+2;
  } else if(x%11==0){
    kaisuu=ans*2;
  } else {
    kaisuu=ans*2+1;
  }

  printf("%lld\n",kaisuu);

  return 0;
}
