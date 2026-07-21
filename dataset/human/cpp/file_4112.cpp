#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>
#include <random>
#include <complex>
#include <functional>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll inf = 1LL << 60;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

typedef complex<long double> co;
struct barrier {
    co c;
    long double r;
};

typedef pair<long double, ll> P;
vector<long double> d;
struct edge {
    ll to;
    long double cost;
};
vector<vector<edge>> G;

void dijkstra (ll s, ll V) {
    priority_queue<P, vector<P>, greater<P>> que;
    d.assign(V, inf);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        ll v = p.second;
        if (d[v] < p.first) continue;
        for (edge e : G[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    long double xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    co s(xs, ys), t(xt, yt);
    ll N;
    cin >> N;
    vector<barrier> b = {{s, 0}, {t, 0}};
    Rep (i, N) {
        long double x, y, r;
        cin >> x >> y >> r;
        b.push_back({co(x, y), r});
    }

    G.assign(N+2, vector<edge>());

    Rep (i, N+2) {
        for (ll j = i+1; j < N+2; j++) {
            long double dist = abs(b[i].c - b[j].c) - b[i].r - b[j].r;
            if (dist < 0) dist = 0;
            G[i].push_back({j, dist});
            G[j].push_back({i, dist});
        }
    }

    dijkstra(0, N+2);

    cout << fixed << setprecision(10) << d[1] << endl;
}
