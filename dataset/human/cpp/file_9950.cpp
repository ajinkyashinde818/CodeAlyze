#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

ll exp(ll a, ll b) {
    ll ret = 1;
    while(1) {
        if (b==0) break;
        if (b%2==1) ret = ret * a % mod;
        a = a * a % mod;
        b>>=1;
    }   
    return ret; 
}

ll inv(ll a) {
    return exp(a, mod-2);
}

ll factorial(ll a, ll b) {
    ll ret = 1;
    while(1) {
        if (b==0) break;
        ret = ret * a % mod;
        --a;
        --b;
    }
    return ret;
}

ll choose(ll a, ll b) {
    if (a < b) swap(a, b);
    ll ret = 1;
    ret = factorial(a, b) * inv(factorial(b, b)) % mod;
    return ret;
}

int main(){
    int n;
    string s;
    cin >> n >> s;
    ll ans = 1;
    ll num = 1;
    vector<int> c(26);
    rep(i, n) ++c[s[i]-'a'];
    //for (auto p: c) {
    //    cout << p << endl;
    //}
    rep(i, 26) {
        ans = ans * (c[i] + 1) % mod;
    }
    cout << ans - 1 << endl;
}
