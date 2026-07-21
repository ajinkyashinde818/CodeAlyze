#include <stdio.h>

long long int gcd(long long int m,long long int n){
    if(m%n==0)
        return n;
    else
        return gcd(n,m%n);
}

int main(){
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld",a*b/gcd(a,b));
}
