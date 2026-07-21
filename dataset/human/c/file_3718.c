#include<stdio.h>
#include<string.h>
int gcd(long long int x, long long int y){
    if (y == 0) return x;
    else        return gcd(y, x % y);
}
int main(){
    long long int a,b,ans,ansb;
    scanf("%lld %lld",&a,&b);
    ans=gcd(a,b);
    ansb=a*b;
    ansb=ansb/ans;
    printf("%lld",ansb);
    return 0;
}
