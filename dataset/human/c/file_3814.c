#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
long long gcd(long long a,long long b){
    a=a%b;
    if(a==0)return b;
    else if(a==1)return 1;
    else return gcd(b,a);
}
long long lcm(long long a,long long b){
return a>b ? a*b/gcd(a,b) : a*b/gcd(b,a);
}
int main(){
    long long a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld",lcm(a,b));
    return 0;
}
