#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T> >;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define repb(i, n) for(ll i = (n)-1; i >= 0; i--)
#define repr(i, a, b) for(ll i = (a); i < (b); i++)
#define reprb(i, a, b) for(ll i = (a)-1; i >= (b); i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
inline ll GCD(ll a, ll b){ return b?GCD(b, a % b):a; }
inline ll LCM(ll a, ll b){ return a/GCD(a, b)*b; }
inline ll powint(unsigned long long x, ll y){ ll r=1; while(y){ if(y&1) r*=x; x*=x; y>>=1; } return r; }
inline ll powmod(ll x, ll y, ll m = MOD){ ll r=1; while(y){ if(y&1) r*=x; x*=x; r%=m; x%=m; y>>=1; } return r; }
template<class S, class T>inline bool chmax(S &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class S, class T>inline bool chmin(S &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n, c;
    cin >> n >> c;
    vll x(n), v(n);
    rep(i, n){
        cin >> x[i] >> v[i];
    }
    
    ll ans = 0;
    ll rval = 0;
    ll rd = 0;
    rep(i, n){
        rval += v[i];
        rd = x[i];
        chmax(ans, rval-rd);
    }
    ll lval = 0;
    ll ld = 0;
    repb(i, n){
        lval += v[i];
        ld = c-x[i];
        chmax(ans, lval-ld);
    }
    
    lval = 0;
    rval = 0;
    ld = 0;
    rd = 0;
    // 右折り返さないコスト
    vll rc1(n);
    // 右折り返すコスト
    vll rc2(n);
    rep(i, n){
        rval += v[i];
        rd = x[i];
        rc1[i] = rval-rd;
        rc2[i] = rval-2*rd;
    }
    // 左折り返さないコスト
    vll lc1(n);
    // 左折り返すコスト
    vll lc2(n);
    repb(i, n){
        lval += v[i];
        ld = c-x[i];
        lc1[i] = lval-ld;
        lc2[i] = lval-2*ld;
    }
    
    vll lc1m(n);
    vll rc1m(n);
    vll lc2m(n);
    vll rc2m(n);
    ll tmp = 0;
    repb(i, n){
        chmax(tmp, lc1[i]);
        lc1m[i] = tmp;
    }
    tmp = 0;
    repb(i, n){
        chmax(tmp, lc2[i]);
        lc2m[i] = tmp;
    }
    tmp = 0;
    rep(i, n){
        chmax(tmp, rc1[i]);
        rc1m[i] = tmp;
    }
    tmp = 0;
    rep(i, n){
        chmax(tmp, rc2[i]);
        rc2m[i] = tmp;
    }
    rep(i, n-1){
        chmax(ans, rc1m[i]+lc2m[i+1]);
        chmax(ans, rc2m[i]+lc1m[i+1]);
    }
    dump(lc1);
    dump(lc1m);
    dump(lc2);
    dump(lc2m);
    dump(rc1);
    dump(rc1m);
    dump(rc2);
    dump(rc2m);
    cout << ans << endl;
    return 0;
}
