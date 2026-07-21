#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <time.h>

long long gcd(long long a,long long b){
    return b?gcd(b,a%b):a;
    }
long long lcm(long long a,long long b){    
    return a/gcd(a,b)*b;
}

int main(void){
    long long a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld\n",lcm(a,b));
    return 0;
}
