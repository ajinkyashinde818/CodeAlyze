#include <stdio.h>
#include <stdlib.h>

int main()
{
  long int a,b,x,r,tmp;
  scanf("%ld %ld",&a,&b);
  x=a*b;

  //a>b
  if(a<b){
    tmp=a;
    a=b;
    b=tmp;
  }

  //ユークリッドの互除法
  r=a%b;
  while(r!=0){
    a=b;
    b=r;
    r=a%b;
  }
  printf("%ld\n",x/b);
  return 0;
}
