#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  long long int i,j,k;
  long long int x,y;
  long long int seki;
  
  scanf("%lld %lld",&x,&y);
  if(x<y){
    i = x;
    x = y;
    y = i;
  }
  
  seki = x*y;

  i = 0;
  i = x%y;
  while( i != 0 ){
    x = y;
    y = i;
    i = x%y;
  }
  
  printf("%lld\n",seki/y);
  
  return 0;
}
