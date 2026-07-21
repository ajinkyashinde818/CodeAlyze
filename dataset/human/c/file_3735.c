#include<stdio.h>
int main(void){
  int a,b,kari,i,r;
  long long x;
  scanf("%d %d",&a,&b);
  x=(long long)a*b;
  if(a<b){
    kari=a;
  a=b;
  b=kari;
  }
r=a%b;
  while(r!=0){
    a=b;
    b=r;
    r=a%b;
  }   
     printf("%lld\n",x/b);
     return 0;
}
