#include "stdio.h"

int main() {
  long long int x;
  long long int ans=0;
  scanf("%lld", &x);

  long long int a = x/11;
  int b = x%11;
  int c = b/6;
  int d = 1;
  if(b%6==0) d = 0;
  ans = 2*a+c+d;
  printf("%lld",ans);
  return 0;
}
