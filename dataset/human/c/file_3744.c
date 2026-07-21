#include<stdio.h>
int main(){
  long a,b,x,c,tmp=0;
  scanf("%ld%ld",&a, &b);
  x=a*b;
  if(a<b){
    tmp=a;
    a=b;
    b=tmp;
  }

  c=a%b;
  while(c!=0){
    a=b;
    b=c;
    c=a%b;
  }
  printf("%ld\n",x/b);
  return 0;
}
