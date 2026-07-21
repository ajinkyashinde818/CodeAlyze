#include<stdio.h>

int gcd(long long a ,long long b){
  if(b == 0){
    return a;
  }
  gcd(b,a%b);
}

int main(void){
  long long a , b;
  scanf("%lld %lld",&a,&b);
  if(a < b){
    long long  temp = a;
    a = b;
    b = temp;
  }
  int g = gcd(a,b);
  long long ans = b * a/g;

  printf("%lld\n",ans);

  return 0;   
}
