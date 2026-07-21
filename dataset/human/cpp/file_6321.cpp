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
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define repr(i, a, b) for(ll i = (a); i < (b); i++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
inline ll GCD(ll a, ll b){ return b?GCD(b, a % b):a; }
inline ll LCM(ll a, ll b){ return a/GCD(a, b)*b; }
inline ll powint(unsigned long long x, ll y){ ll r=1; while(y){ if(y&1) r*=x; x*=x; y>>=1; } return r; }
inline ll powmod(ll x, ll y, ll m = MOD){ ll r=1; while(y){ if(y&1) r*=x; x*=x; r%=m; x%=m; y>>=1; } return r; }
template<class T>bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif

// ModInt
// 参考：https://ei1333.github.io/luzhiled/snippets/math/mod-int.html
// modはコンパイル時に決定

template<ll mod> class ModInt{
public:
    ll x;
    ModInt() : x(0) {}
    ModInt(ll y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod){}
    constexpr ModInt &operator+=(const ModInt &p){
        if((x += p.x) >= mod) x -= mod;
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt &p){
        if((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt &p){
        x = x * p.x % mod;
        return *this;
    }
    constexpr ModInt &operator/=(const ModInt &p){
        *this *= p.inverse();
        return *this;
    }
    constexpr ModInt operator-(){ return ModInt(-x); }
    constexpr ModInt operator+(const ModInt &p){ return ModInt(*this) += p; }
    constexpr ModInt operator-(const ModInt &p){ return ModInt(*this) -= p; }
    constexpr ModInt operator*(const ModInt &p){ return ModInt(*this) *= p; }
    constexpr ModInt operator/(const ModInt &p){ return ModInt(*this) /= p; }
    constexpr bool operator==(const ModInt &p){ return x == p.x; }
    constexpr bool operator!=(const ModInt &p){ return x != p.x; }
    constexpr ModInt inverse() const{
        ll a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }
    constexpr ModInt pow(ll n) {
        ModInt ret(1), mul(x);
        while(n > 0) {
            if(n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    friend ostream &operator<<(ostream &os, const ModInt &p){
        return os << p.x;
    }
    friend istream &operator>>(istream &is, ModInt &a){
        ll t;
        is >> t;
        a = ModInt< mod >(t);
        return (is);
    }
};

using mint = ModInt<MOD>;

const int MAX = 100010;
mint fac[MAX], facinv[MAX];
void combInit(){
    fac[0] = mint(1);
    facinv[0] = mint(1);
    rep(i, MAX-1){
        fac[i+1] = fac[i]*(i+1);
        facinv[i+1] = fac[i+1].inverse();
    }
}
mint comb(const ll a, const ll b){
    assert(a < MAX);
    assert(b < MAX);
    if(a < 0 || b < 0 || b > a){
        return mint(0);
    }
    mint ret(1);
    ret *= fac[a];
    ret *= facinv[b];
    ret *= facinv[a-b];
    return ret;
}

void pr(ll n){
    cout << n << endl;
    exit(0);
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    combInit();
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if(s[0] == 'W' || s[2*n-1] == 'W'){
        pr(0);
    }
    mint ans(fac[n]);
    
    ll thrown = 0;
    rep(i, 2*n){
        int f1 = thrown&1;
        int f2 = (s[i] == 'B');
        dump(f1, f2);
        if(f1 ^ f2){
            // right
            thrown++;
        }else{
            // left
            ans *= thrown;
            dump(thrown);
            thrown--;
            if(thrown < 0){
                pr(0);
            }
        }
    }
    if(thrown != 0){
        pr(0);
    }
    cout << ans << endl;
    return 0;
}
