#include <stdio.h>

long long gcd(long long a,long long b){long long r,tmp;if(a < b){tmp = a;a = b;b = tmp;}r = a % b;while(r != 0){a = b;b = r;r = a % b;}return b;}
long long lcm(long long a,long long b){long long r;r = gcd(a,b);r = a * b / r;return r;}

int main()
{
    long long a,b;
    scanf("%lld %lld",&a,&b);

    printf("%lld",lcm(a,b));
}
