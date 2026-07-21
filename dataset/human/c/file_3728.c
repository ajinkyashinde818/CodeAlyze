#include<stdio.h>
int main(void){
  long long a, b, i, max;
  scanf("%lld %lld", &a, &b);
  if(a<b){max=b;}
  else{max=a;}
  for(i=max;i>0;i--){
    if(a%i==0&&b%i==0){
      if(a<b){a=a/i;}
      else{b=b/i;}
    }
  }
  printf("%lld", a*b);
}
