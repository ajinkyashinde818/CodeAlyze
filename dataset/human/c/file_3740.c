// C - Snack
#include <stdio.h>
typedef long long ll;

ll gcd(ll a, ll b){
    if(a%b==0) return b;
    else gcd(b, a%b);
}

int main(void){
    ll a, b;
    scanf("%lld%lld", &a, &b);
    // printf("gcd:%d\n", gcd(a, b));
    printf("%lld\n", a*b/gcd(a, b));
    return 0;
}
