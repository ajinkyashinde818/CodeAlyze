#include<stdio.h>
long long int gcd(long long int a,long long int b){
  long long int i;
  while(a!=0 && b!=0){
    i=b;
    b=a%b;
    a=i;
  }
  return a;
}

int main(){
  long long a,b,c;
  scanf("%lld%lld",&a,&b);
  c=a*b/gcd(a,b);
  printf("%lld\n",c);
  return 0;
}
