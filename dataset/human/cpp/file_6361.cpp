#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <bitset>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;
using Pii = pair<int, int>;

constexpr ll MOD = 1000000007;
constexpr long double EPS = 1e-10;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};
constexpr int N_MAX = 100000;

ll fact[N_MAX+1], rfact[N_MAX+1];

void init(ll n){
    fact[0] = fact[1] = 1;
    rfact[0] = rfact[1] = 1;
    for(int i=2;i<=n;++i) {
        fact[i] = (fact[i-1] * (ll)i) % MOD;
        rfact[i] = 1;
        ll k = MOD-2;
        ll a = fact[i];
        while(k > 0){
            if(k & 1){
                rfact[i] *= a;
                rfact[i] %= MOD;
            }
            a *= a;
            a %= MOD;
            k  >>= 1;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> a(2*n);
    for(int i=0;i<2*n;++i) a[i] = (s[i]=='B')?1:0;
    init(n);

    if(a[0] == 0 || a[2*n-1] == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<ll> is_l(2*n, 1);
    for(int i=1;i<2*n;++i) {
        if(a[i-1] == a[i]) {
            is_l[i] = 1-is_l[i-1];
        } else {
            is_l[i] = is_l[i-1];
        }
    }

    if(accumulate(is_l.begin(), is_l.end(), 0) != n) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1LL;
    for(int i=1;i<2*n;++i) {
        if(!is_l[i]) {
            ans *= is_l[i-1];
            ans %= MOD;
            --is_l[i-1];
        }
        is_l[i] += is_l[i-1];
    }
    ans *= fact[n];
    ans %= MOD;
    cout << ans << endl;
}

/*
4
BWBBWWWB
*/
