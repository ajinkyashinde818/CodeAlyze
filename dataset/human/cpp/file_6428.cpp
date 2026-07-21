#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

typedef long long ll;
const ll inf = 1e15;
ll mod = 1000000007;

ll modfact(ll a) {
    ll res = 1;
    while(a) {
        res = res * a % mod;
        a--;
    }
    return res;
}

int main() {
    ll n;
    scanf("%lld",&n);
    string s;
    cin>>s;
    string col(2*n,' ');
    col[0] = 'L';
    ll lnum = 1;
    ll rnum= 0;
    for (int i = 1; i < 2 * n; i++) {
        if (s[i] == s[i - 1]) {
            if (col[i - 1] == 'L') col[i] = 'R',rnum++;
            else col[i] = 'L',lnum++;
        } else {
            if (col[i - 1] == 'L') col[i] = 'L',lnum++;
            else col[i] = 'R',rnum++;
        }
    }

    if (lnum != rnum || s[0] == 'W' || s[2*n-1] == 'W') {
        printf("%d\n",0);
        return 0;
    }

    vector<ll> lnums(2 * n, 0);
    for (int i = 1; i < 2 * n; i++) {
        if (col[i - 1] == 'L') lnums[i] = lnums[i - 1] + 1;
        else lnums[i] = lnums[i - 1];
    }

    ll ans = 1;
    for (int i = 1; i < 2 * n; i++) {
        if (col[i] == 'R') ans = ans * (2 * lnums[i] - i) % mod;
    }
    ans = ans * modfact(n) % mod;
    printf("%lld\n",ans);
    return 0;
}
