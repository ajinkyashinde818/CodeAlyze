#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long
#define ull unsigned long long

long long gcd(long long x, long long y){
    return y == 0 ? x : gcd(y, x % y);
}

long long lcm(long long x,long long y){
    return x / gcd(x,y) * y;
}

int main(){
    long long a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld",lcm(a, b));
    return 0;
}
