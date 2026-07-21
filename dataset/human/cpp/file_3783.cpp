#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    double xs, ys, xt, yt;
    ll N;
    cin >> xs >> ys >> xt >> yt >> N;

    N += 2;

    vector<double> x(N), y(N), r(N);
    for (ll i = 0; i < N - 2; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    x[N - 2] = xs;
    y[N - 2] = ys;
    x[N - 1] = xt;
    y[N - 1] = yt;
    r[N - 2] = r[N - 1] = 0.0;

    constexpr double INF = 1e10;
    vector<vector<double>> edges(N, vector<double>(N, INF));
    for (ll i = 0; i < N; i++) {
        for (ll j = i; j < N; j++) {
            double d = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
            edges[i][j] = edges[j][i] = max(d - r[i] - r[j], 0.0);
        }
    }

    //ダイクストラ
    vector<double> cost(N, INF);
    struct Element {
        ll node;
        double cost;
        bool operator<(const Element& rhs) const {
            return cost < rhs.cost;
        }
        bool operator>(const Element& rhs) const {
            return cost > rhs.cost;
        }
    };
    priority_queue<Element, vector<Element>, greater<Element>> pq;

    cost[N - 2] = 0;
    pq.push({ N - 2, 0.0 });
    while (!pq.empty()) {
        Element t = pq.top();
        pq.pop();
        if (t.cost > cost[t.node]) {
            continue;
        }

        for (ll i = 0; i < N; i++) {
            double new_cost = t.cost + edges[t.node][i];
            if (new_cost < cost[i]) {
                cost[i] = new_cost;
                pq.push({ i, new_cost });
            }
        }
    }

    printf("%.10f\n", cost[N - 1]);
}
