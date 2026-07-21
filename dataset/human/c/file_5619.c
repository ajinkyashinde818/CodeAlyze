#include <stdio.h>
#include <string.h>

int main(){
  long long int x,count=0;

  scanf("%lld",&x);

  count+=(x/11)*2;
  x-=count/2*11;
  if(x>=7)count+=2;
  else if(0<x&&6>=x) count++;

  printf("%lld\n",count);

  return 0;
}
