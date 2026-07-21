#include <bits/stdc++.h>
using namespace std;

typedef unsigned long ul;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> vint;
typedef vector< vector<ll> > vvint;
typedef vector< vector< vector<ll> > > vvvint;
typedef vector<string> vstring;
typedef vector< vector<string> > vvstring;
typedef vector<char> vchar;
typedef vector< vector<char> > vvchar;
typedef vector<long double> vdouble;
typedef vector< vector<long double> > vvdouble;
typedef vector< vector< vector<long double> > > vvvdouble;
typedef pair<ll,ll> pint;
typedef vector<pint> vpint;
typedef vector<bool> vbool;

#define rep(i,n) for(ll i=0;i<n;i++)
#define repf(i,f,n) for(ll i=f;i<n;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define ALL(obj) (obj).begin(), (obj).end()
// #define LLONG_MAX 9223372036854775806
#define vmax(vec) *max_element(vec.begin(), vec.end())
#define vmin(vec) *min_element(vec.begin(), vec.end())
#define vsort(vec) sort(vec.begin(), vec.end())
#define vsortgr(vec) sort(vec.begin(), vec.end(), greater<ll>())
#define MOD 1000000007
// #define MOD 998244353
// #define MOD LLONG_MAX
const double PI=3.14159265358979323846;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0,};

void printv(vint &v){
    for(auto e:v) cout<<e<<" ";
        cout<<endl;
    }

// 繰り返し二乗法
ll power(ll a, ll b){
    if(a==1)return a;
    // if(a==0)re
    ll res=1;
    while(b>0){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

const int MAX=2100000;

ll fact[MAX], fact_inv[MAX];

void init_fact(ll n){
    fact[0]=1;
    // 階乗の計算
    for(ll i=0; i<n; i++) fact[i+1]=fact[i]*(i+1)%MOD;
    fact_inv[n]=power(fact[n], MOD-2);
    // 逆元の計算
    for(ll i=n-1;i>=0;i--) fact_inv[i]=fact_inv[i+1]*(i+1)%MOD;
}

ll comb(ll n, ll r){
    return (fact[n]*fact_inv[r])%MOD*fact_inv[n-r]%MOD;
}

ll perm(ll n, ll r){
    return (fact[n]*fact_inv[n-r])%MOD;
}
using ld = long double;
int main() {
    cout<<fixed<<setprecision(10);

    ll xs,ys,xt,yt; cin>>xs>>ys>>xt>>yt;
    ll n; cin>>n;
    vint x(n),y(n),r(n);
    rep(i,n) cin>>x[i]>>y[i]>>r[i];
    x.push_back(xs);
    y.push_back(ys);
    r.push_back(0);
    x.push_back(xt);
    y.push_back(yt);
    r.push_back(0);

    auto cc = [](ll x1, ll y1, ll r1, ll x2, ll y2, ll r2){
        ld d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        return max((ld)0, d - (r1 + r2));
    };



    vvdouble D(n+2, vdouble(n+2));

    // cc
    rep(i,n+2){
        rep(j,n+2){
            D[i][j] = cc(x[i], y[i], r[i], x[j], y[j], r[j]);
        }
    }

    const ld dmax = 1e13;
    vdouble dist(n+2, dmax);
    priority_queue<pair<ld, ll>> pq; // -d, index
    pq.push(mp((ld)0.0, n));

    while(!pq.empty()){
        ld d; ll src;
        tie(d, src) = pq.top(); pq.pop();
        if(dist[src] < dmax) continue;
        dist[src] = -d;
        rep(to, n+2){
            if(dist[to] < dmax) continue;
            pq.push(mp(d-D[src][to], to));
        }
    }
    cout<<dist[n+1]<<endl;

    return 0;

}
