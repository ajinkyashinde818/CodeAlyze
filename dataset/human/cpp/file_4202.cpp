#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;
    ll n; cin >> n;
    V<double> x(n+1), y(n+1), r(n+1, 0);
    V<double> d(n+1, HIGHINF);
    priority_queue<P<double, ll>, V<P<double, ll> >, greater<P<double, ll> > > que;
    REP(i, n) {
        cin >> x[i] >> y[i] >> r[i];
        double tmpd = sqrt((x[i]-xs)*(x[i]-xs) + (y[i]-ys)*(y[i]-ys));
        d[i] = max(tmpd - r[i], 0.0);
        if (d[i] < 0) d[i] = 0;
        que.push(make_pair(d[i], i));
    }
    x[n] = xt; y[n] = yt;
    d[n] = sqrt((xt-xs)*(xt-xs) + (yt-ys)*(yt-ys));
    
    V<bool> visit(n+1);
    while (!que.empty()) {
        P<double, ll> q = que.top(); que.pop();
        if (visit[q.second]) continue;
        visit[q.second] = true;
        REP(i, n+1) {
            if (visit[i]) continue;
            ll u = q.second;
            if (sqrt((x[i]-x[u])*(x[i]-x[u]) + (y[i]-y[u])*(y[i]-y[u])) < r[i]+r[u]) {
                chmin(d[i], q.first);
                que.push(make_pair(d[i], i));
            } else {
                double tmpd = sqrt((x[i]-x[u])*(x[i]-x[u]) + (y[i]-y[u])*(y[i]-y[u])) - r[i] - r[u];
                if (d[i] > d[u]+tmpd) {
                    d[i] = d[u]+tmpd;
                    que.push(make_pair(d[i], i));
                }
            }
        }
    }
    cout << fixed << setprecision(12) << d[n] << endl;
    return 0;
}
