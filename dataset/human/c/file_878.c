#include<stdio.h>
#define ll long long
ll prime(ll n){
    if(n < 2) return 0;
    for(ll i = 2; i * i <= n; i++)
        if(n % i == 0)
            return i;
    return n;
}
int main(){
    ll n;
    scanf("%lld",&n);
    ll p, q, r, ans = 0;
    while(n > 1){
        p = prime(n);
        q = 0;
        while(n % p == 0){
            q++;
            n /= p;
        }
        r = 1;
        while(r * (r + 1) / 2 <= q)
            r++;
        ans += r - 1;
    }
    printf("%lld\n",ans);
    return 0;
}
