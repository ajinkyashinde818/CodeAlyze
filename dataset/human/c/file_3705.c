#include<stdio.h>
int main(void)
{
  long int a,b,i,c,d,e;
  scanf("%ld",&a);
  scanf("%ld",&b);
  if(a>=b){
    c=a;
    d=b;
  }
  if(b>a){
    c=b;
    d=a;
  }
  for(i=1;i<=d;i++){
    e=c*i;
    if(e%d==0){
      printf("%ld\n",e);
      break;
    }
    if(e%d!=0){
      continue;
    }
  }
  return 0;
}
