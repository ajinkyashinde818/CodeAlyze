#include <iostream>
#include <iomanip>
#include <algorithm>
#include <assert.h>
#include <complex>
#include <utility>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <cmath>
#include <bitset>
#include <cctype>
#include <set>
#include <map>
#include <unordered_map>
#include <numeric>
#include <functional>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define rrep(i,a) for(ll i=ll(a-1);i>=0;--i)
#define all(x) (x).begin(),(x).end()
#define PRINT(V) cout << V << "\n"
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())
using namespace std;
using ll = long long;
using ull = unsigned long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
inline void Yes(bool condition){ if(condition) PRINT("Yes"); else PRINT("No"); }
template<class itr> void cins(itr first,itr last){
    for (auto i = first;i != last;i++){
        cin >> (*i);
    }
}
template<class itr> void array_output(itr start,itr goal){
    string ans = "",k = " ";
    for (auto i = start;i != goal;i++) ans += to_string(*i)+k;
    if (!ans.empty()) ans.pop_back();
    PRINT(ans);
}
ll gcd(ll a, ll b) {
    return a ? gcd(b%a,a) : b;
}

const ll INF = 1e18;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const ll MOD3 = 1e6;
const ll EPS = 1e-10;
int sgn(const double a){
    return (a < -EPS ? -1 : (a > EPS ? +1 : 0));
}
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> tri;
typedef pair<long double,long double> point;
typedef complex<long double> Point;
const ll MAX = 3000;
constexpr ll nx[4] = {-1,0,1,0};
constexpr ll ny[4] = {0,1,0,-1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> a(n+1,0),b(n+1,0),s,t;
    rep(i,n){
        ll c;
        cin >> c;
        s.push_back(c);
        a[c]++;
    }
    rep(i,n){
        ll c;
        cin >> c;
        t.push_back(c);
        b[c]++;
    }
    rep(i,1,n+1){
        if (a[i]+b[i] > n){
            PRINT("No");
            return 0;
        }
    }
    vector<ll> ans(n);
    ll i = 0;
    while (i < n && s[n-i-1] != t[i]){
        ans[n-i-1] = t[i];
        i++;
    }
    ll j = 0;
    while (i < n){
        ans[j] = t[i];
        j++;
        i++;
    }
    bool ok = 1;
    rep(i,n){
        if (s[i] == ans[i]) ok = 0;
    }
    if (ok){
        PRINT("Yes");
        array_output(all(ans));
        return 0;
    }
    i = 0;
    while (i < n && s[i] != t[n-i-1]){
        ans[i] = t[n-i-1];
        i++;
    }
    j = 0;
    while (i < n){
        ans[i] = t[j];
        j++;
        i++;
    }
    ok = 1;
    rep(i,n){
        if (s[i] == ans[i]) ok = 0;
    }
    if (ok){
        PRINT("Yes");
        array_output(all(ans));
        return 0;
    }
    ll ma = 0;
    rep(i,1,n+1){
        chmax(ma,a[i]);
    }
    rep(i,n){
        ans[(i+ma)%n] = t[i];
    }
    PRINT("Yes");
    array_output(all(ans));
}
