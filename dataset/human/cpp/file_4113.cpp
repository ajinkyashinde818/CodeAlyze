#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
using ll = long long;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-10;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

using P = complex<double>;
using Data = pair<double, int>;
struct Circle {
    P p;
    double r;
    Circle() = default;
    Circle(P _p, double _r) : p(_p), r(_r) {}
};
struct edge {
    int to;
    double cost;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    double xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    int n;
    cin >> n;
    vector<Circle> v(n + 2);
    v[0] = Circle(P(xs, ys), 0);
    v[n + 1] = Circle(P(xt, yt), 0);
    for(int i = 1; i <= n; i++) {
        double x, y, r;
        cin >> x >> y >> r;
        v[i] = Circle(P(x, y), r);
    }
    auto calcCost = [&](Circle c1, Circle c2) {
        return max(abs(c1.p - c2.p) - c1.r - c2.r, 0.0);
    };
    vector<vector<edge>> g(n + 2);
    for(int i = 0; i < n + 2; i++) {
        for(int j = 0; j < n + 2; j++) {
            if(i != j) {
                g[i].emplace_back(edge{j, calcCost(v[i], v[j])});
            }
        }
    }
    vector<double> d(n + 2, LLINF);
    priority_queue<Data, vector<Data>, greater<Data>> que;
    d[0] = 0;
    que.push(Data(0, 0));
    while(que.size()) {
        auto now = que.top();
        que.pop();
        double nd = now.first;
        int nv = now.second;
        if(nd > d[nv] + EPS) {
            continue;
        }
        for(const auto &e : g[nv]) {
            if(d[e.to] > nd + e.cost + EPS) {
                d[e.to] = nd + e.cost;
                que.push(Data(d[e.to], e.to));
            }
        }
    }
    cout << fixed << setprecision(15);
    cout << d[n + 1] << endl;
}
