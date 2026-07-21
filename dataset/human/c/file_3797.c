#include <stdio.h>

long long int gcd(long long int a, long long int b){
  	long long int tmp;
    if(a<b){tmp=a;a=b;b=tmp;}
    if(b == 0)return a;
    return gcd(b, a%b);
}

long long int lcm(long long int a, long long int b){
    return a * b / gcd(a, b);
}

int main(){
  long long int A,B;
  scanf("%lld %lld",&A,&B);
  printf("%lld\n",lcm(A,B));
}
