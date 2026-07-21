#include<stdio.h>
#include<stdlib.h>
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
int main(){
  long long n,a,b,c,d,e;
  scanf("%lld",&n);
  while(n--){
    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
    if(a<b)goto NO;
    if(d<b)goto NO;
    if(c>=b)goto YES;
    if(c>=a)goto YES;
    if(b-c<2)goto YES;
    e=(a-c)%gcd(d,b);
    if(e==0)e=gcd(d,b);
    //if(gcd(d,b)==1)goto NO;
    if(e<(b-c))goto NO;
  YES:;
    printf("Yes\n");
    continue;
  NO:;
    printf("No\n");
    continue;
  }
  return 0;
}
