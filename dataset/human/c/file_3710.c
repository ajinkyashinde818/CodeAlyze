#include <stdio.h>
long long gcd(long long p,long long q){
    if(p%q==0) return q;
    else return gcd(q,p%q);
}
int main(void){
    long long a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld",a*b/gcd(a,b));
    return 0;
}
