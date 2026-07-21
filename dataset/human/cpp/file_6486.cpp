#include <bits/stdc++.h>
using namespace std;using ll=int_fast64_t;using ld=long double;using pll=pair<ll,ll>;constexpr ll INF=1LL<<60,MOD=1e9+7;//998244353;
void solve();int main(){cin.tie(nullptr);ios::sync_with_stdio(false);cout<<fixed<<setprecision(10);solve();return 0;}
#define SELECTOR(_1,_2,_3,_4,SELECT,...) SELECT
#define rep(...) SELECTOR(__VA_ARGS__,_rep2,_rep1,_rep0)(__VA_ARGS__)
#define _rep0(i,n) for(ll i=0;i<n;++i)
#define _rep1(i,k,n) for(ll i=k;i<n;++i)
#define _rep2(i,k,n,d) for(ll i=k;d>0?i<n:i>n;i+=d)
#define endl "\n"
#ifdef __LOCAL
#include "ostreams.h"
#endif
template<class T> inline bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}
template<class T> vector<T> make_vector(size_t a,T b){return vector<T>(a,b);}
template<class... Ts> auto make_vector(size_t a,Ts... ts){return vector<decltype(make_vector(ts...))>(a,make_vector(ts...));}
void print(){cerr<<endl;} template<class T,class... Ts> void print(const T& a,const Ts&... ts){cerr<<a<<' ';print(ts...);}

template<ll MOD>
class Modint{
private:
    ll x;
public:
    constexpr Modint(ll v = 0) : x(v % MOD + (v >= 0 ? 0 : MOD)) {}
    constexpr Modint operator+(const Modint &rhs) const {return Modint(*this) += rhs;}
    constexpr Modint operator-(const Modint &rhs) const {return Modint(*this) -= rhs;}
    constexpr Modint operator*(const Modint &rhs) const {return Modint(*this) *= rhs;}
    constexpr Modint operator/(const Modint &rhs) const {return Modint(*this) /= rhs;}
    constexpr Modint operator+=(const Modint &rhs) {x += rhs.x; if(x >= MOD) x -= MOD; return *this;}
    constexpr Modint operator-=(const Modint &rhs) {x -= rhs.x; if(x < 0) x += MOD; return *this;}
    constexpr Modint operator*=(const Modint &rhs) {(x *= rhs.x) %= MOD; return *this;}
    constexpr Modint operator/=(const Modint &rhs) {return *this *= pow(rhs, -1);}
    template<class T> constexpr explicit operator T() const {return x;}
    constexpr static Modint pow(Modint a, ll p){
        if(p < 0){
            ll b = MOD, u = 1, v = 0;
            while(b){ll t = a.x / b; a.x -= t * b; a.x += b; b = a.x - b; a.x -= b; u -= t * v; u += v; v = u - v; u -= v;}
            a = u; p *= -1;}
        Modint res = 1;
        while(p){if(p & 1) res *= a; a *= a; p >>= 1;}
        return res;
    }
    constexpr void from_stream(istream &st) {st >> x;}
    constexpr void to_stream(ostream &st) const {st << x;}
};
template<ll MOD, class T> constexpr Modint<MOD> operator+(T a, Modint<MOD> b){return (Modint<MOD>)a + b;}
template<ll MOD, class T> constexpr Modint<MOD> operator-(T a, Modint<MOD> b){return (Modint<MOD>)a - b;}
template<ll MOD, class T> constexpr Modint<MOD> operator*(T a, Modint<MOD> b){return (Modint<MOD>)a * b;}
template<ll MOD, class T> constexpr Modint<MOD> operator/(T a, Modint<MOD> b){return (Modint<MOD>)a / b;}
template<ll MOD> constexpr istream& operator>>(istream &st, Modint<MOD> &a){a.from_stream(st); return st;}
template<ll MOD> constexpr ostream& operator<<(ostream &st, const Modint<MOD> &a){a.to_stream(st); return st;}
using mint = Modint<MOD>;

template<ll N>
class Modfact{
private:
    ll _fact[N + 1], _invfact[N + 1];
public:
    constexpr Modfact() : _fact(), _invfact() {
        _fact[0] = 1; rep(i, N) _fact[i + 1] = _fact[i] * (i + 1) % MOD;
        _invfact[N] = (ll)mint::pow(_fact[N], -1);
        rep(i, N - 1, -1, -1) _invfact[i] = _invfact[i + 1] * (i + 1) % MOD;
    }
    constexpr mint fact(ll n) const {return _fact[n];}
    constexpr mint invfact(ll n) const {return _invfact[n];}
    constexpr mint comb(ll n, ll k) const {return 0 <= k && k <= n ? (mint)_fact[n] * _invfact[k] * _invfact[n - k] : 0;}
    constexpr mint perm(ll n, ll k) const {return 0 <= k && k <= n ? (mint)_fact[n] * _invfact[n - k] : 0;}
};
#ifdef __LOCAL
constexpr ll N_MAX = 10000;
#else
constexpr ll N_MAX = 2000005;
#endif
constexpr Modfact<N_MAX> mf;

void solve(){
    ll n; cin >> n;
    string S; cin >> S;
    rep(i, 0, 2 * n, 2){
        if(S[i] == 'B'){
            S[i] = 'W';
        } else {
            S[i] = 'B';
        }
    }

    if(count(S.begin(), S.end(), 'W') != n){
        cout << 0 << endl;
        return;
    }

    // print(S);
    mint res = mf.fact(n);
    ll white = 0;
    for(auto c : S){
        if(c == 'W'){
            white ++;
        } else {
            res *= white;
            white --;
        }
    }
    cout << res << endl;
}
