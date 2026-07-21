#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5;
typedef long long ll;
char s[maxn];
const ll p = 1e9+7;
ll n, qk[maxn], jc[maxn];

signed main(){
    scanf("%lld %s", &n, (s+1));
    jc[0] = 1;
    for(int i = 1; i <= n; i++) jc[i] = jc[i-1] * i % p;
    int tot = 0, valid = 1;
    for(int  i =1; i <= n*2; i++) {
        if(s[i] == 'B') {
            if(tot % 2 == 0) qk[i] = 1, tot++;
            else qk[i] = -1, tot--;
        } else {
            if(tot % 2 == 0) qk[i] = -1, tot--;
            else qk[i] = 1,  tot++;
        }
        if(tot < 0) valid = 0;
    }
    if(tot > 0) valid = 0;
    if(valid == 0) {
        puts("0"); 
        return 0; 
    }

    ll ans = 1, sum = 0;
    for(int i = 1; i <= 2*n; i++) {
        if(qk[i] == -1) ans = ans * sum % p;
        sum += qk[i];
        // printf("%lld ", qk[i]);
    }
    ans = ans * jc[n] % p;

    printf("%lld\n", ans);
    return 0;
}
