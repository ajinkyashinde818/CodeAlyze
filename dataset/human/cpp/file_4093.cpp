#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;

using ll = long long;
using P = pair<double, int>;    // (時間, 頂点)

const int MAXN = 1010;

double dist[MAXN];

ll sq(ll x) {
    return x * x;
}

int main() {
    ll xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;

    int N;
    cin >> N;

    vector<ll> x(N + 2, 0), y(N + 2, 0), r(N + 2, 0);
    for (int i = 1; i <= N; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    x[0] = xs; y[0] = ys;
    x[N + 1] = xt; y[N + 1] = yt;

    for (int i = 0; i < MAXN; i++) dist[i] = 1e18;

    priority_queue<P, vector<P>, greater<P>> que;

    dist[0] = 0;
    que.push(make_pair(0, 0));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        double cost = p.first;

        if (cost > dist[v]) continue;

        for (int to = 0; to <= N + 1; to++) {
            double ncost = cost + max(0.0, sqrt(sq(x[v] - x[to]) + sq(y[v] - y[to])) - r[v] - r[to]);

            if (dist[to] > ncost) {
                dist[to] = ncost;
                que.push(make_pair(dist[to], to));
            }
        }
    }
    cout << fixed << setprecision(10) << dist[N + 1] << endl;

    return 0;
}
