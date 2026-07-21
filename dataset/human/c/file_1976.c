#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  long long int a,b,c;
  scanf("%lld",&a);
  scanf("%lld",&b);
  scanf("%lld",&c);
  long long int ans;
  if (a+b+1 >= c) {//all cockies
    ans = c+b;
  } else {
    ans = a+b+1+b;
  }
  printf("%lld\n",ans);
  return 0;
}
