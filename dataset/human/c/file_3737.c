#include<stdio.h>
long long gcd(long long a,long long b){return b == 0 ? a : gcd(b, a % b);}
long long lcm(long long a,long long b){return a / gcd(a, b) * b;}
int main(){
    long long a, b;
    scanf("%lld%lld",&a,&b);
    printf("%lld\n",lcm(a, b));
    return 0;
}
