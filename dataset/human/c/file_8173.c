#include<stdio.h>
int main(){
  int a,b,c,d;
  long long int ar;
  scanf("%d %d %d %d\n",&a,&b,&c,&d);
  long long int ar1,ar2;
  ar1 = a*b;
  ar2 = c*d;
  if(ar1>=ar2) ar = ar1;
  else ar =ar2;
  printf("%lld\n",ar);
  return 0;
}
