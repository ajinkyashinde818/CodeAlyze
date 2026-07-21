#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
typedef long long ll;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
#define max(l,r) ((l)>(r)?l:r)
#define min(l,r) ((l)<(r)?l:r)
const ll MOD = 1000000007;

int main(){
    //input
    int n;
    scanf("%d", &n);
    char s[101010];
    scanf("%s", s);

    //solve
    ll ans = 1;
    int cnt[28] = {0};
    rep(i ,n) cnt[s[i] - 'a']++;
    rep(i, 26) {
        ans *= cnt[i]+1;
        ans %= MOD;
    }
    ans = (ans - 1) % MOD;

    //output
    printf("%lld", ans);
}
