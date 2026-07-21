#include <stdio.h>
#include <stdlib.h>

#define ll long long

#define MOD 998244353

int main(){
    ll n;
    scanf("%lld", &n);

    ll ans = 0;
    for(ll i=2;i*i<=n;i++){
        ll j = i;
        while(n%j==0){
            n /= j;
            j *= i;
            ans++;
        }
        while(n%i==0){
            n /= i;
        }
        if(n<i){
            break;
        }
    }
    if(n>1){
        ans += 1;
    }

    printf("%lld\n", ans);

    return 0;
}
