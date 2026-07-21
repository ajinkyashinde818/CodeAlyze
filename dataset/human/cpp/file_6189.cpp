#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using ll = long long;
enum : int { M = (int)1e9 + 7 };
enum : ll { MLL = (ll)1e18L + 9 };
using namespace std;
#ifdef LOCAL
#include"rprint2.hpp"
#include"debug_deque.hpp"
#define vector DebugDeque
#else
#define FUNC(name) template <ostream& out = cout, class... T> void name(T&&...){ }
FUNC(prints) FUNC(printe) FUNC(printw) FUNC(printew) FUNC(printb) FUNC(printd) FUNC(printde);
#endif
template <class S, class T>
istream& operator >> (istream& in, pair<S, T>& p){ in >> p.first >> p.second; return in; }
template <class T>
istream& operator >> (istream& in, vector<T>& v){ for(auto& e : v){ in >> e; } return in; }
// template <char d = ' ', class T>
// ostream& operator << (ostream& out, vector<T>& v){ for(auto& e : v){ out << e << d; } return out; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, c;
    cin >> n >> c;
    vector<pair<ll, ll>> xvs(n); cin >> xvs;
    auto xvr = xvs;
    reverse(xvr.begin(), xvr.end());
    for(auto& r : xvr){
        r.first = c - r.first;
    }
    ll acc = 0;
    for(int i = 0; i < n; i++){ xvs[i].second -= xvs[i].first - acc; acc = xvs[i].first; }
    acc = 0;
    for(int i = 0; i < n; i++){ xvr[i].second -= xvr[i].first - acc; acc = xvr[i].first; }
    vector<ll> maxs(n + 1), maxr(n + 1);
    acc = 0;
    for(int i = 1; i <= n; i++){
        acc += xvs[i - 1].second;
        maxs[i] = max(maxs[i - 1], acc);
    }
    acc = 0;
    for(int i = 1; i <= n; i++){
        acc += xvr[i - 1].second;
        maxr[i] = max(maxr[i - 1], acc);
    }
    ll ans = 0;
    printd(xvs);
    printd(xvr);
    printd(maxs);
    printd(maxr);
    acc = 0;
    ll accr = 0;
    for(int i = 0; i <= n; i++){
        ans = max(ans, maxr[i]);
        ans = max(ans, maxs[i]);
        ans = max(ans, maxr[i] + maxs[n - i] - acc);
        ans = max(ans, maxs[i] + maxr[n - i] - accr);
        if(i < n){
            acc = xvr[i].first;
            accr = xvs[i].first;
        }
        printd(i, ans);
    }
    cout << ans << '\n';
}
