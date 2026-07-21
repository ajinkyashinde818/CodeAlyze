#include <stdio.h>

int gcd(int a, int b){
  if(b==0){
    return a;
  } else {
    return gcd(b,a%b);
  }
}

int main(){
  int a,b,tmp;
  scanf("%d %d",&a,&b);
  if(a<b){
    tmp=b;
    b=a;
    a=tmp;
  }
  tmp=gcd(a,b);
  printf("%ld",(long)a*b/tmp);
}
