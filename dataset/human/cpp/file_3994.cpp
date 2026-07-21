#include <bits/stdc++.h>
using namespace std;

struct edge {
    int to; double dist;
    edge(int _to, double _dist) {
        to = _to; dist = _dist;
    }
};

struct circle {
    double x, y, r;
    circle(double _x, double _y, double _r) {
        x = _x; y = _y; r = _r;
    };
};

double dist(circle &a, circle &b) {
    double ret = sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2)) - (a.r+b.r);
    return max(0.0, ret);
}

int main() {
    vector<circle> v;
    for (int i = 0; i < 2; i++) {
        double x, y; cin >> x >> y;
        v.emplace_back(x, y, 0);
    }
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        double x, y, r; cin >> x >> y >> r;
        v.emplace_back(x, y, r);
    }
    n += 2;
    vector<edge> e[n];
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            double d = dist(v[i], v[j]);
            e[i].emplace_back(j, d);
            e[j].emplace_back(i, d);
        }
    }
    vector<double> a(n, 1e32); a[0] = 0;
    priority_queue<pair<double, int>> pq;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        pair<double, int> s = pq.top(); pq.pop();
        if (-s.first > a[s.second]) continue;
        int cur = s.second;
        for (int i = 0; i < e[cur].size(); i++) {
            int to = e[cur][i].to;
            if (a[to] > a[cur] + e[cur][i].dist) {
                a[to] = a[cur] + e[cur][i].dist;
                pq.emplace(-a[to], to);
            }
        }
    }
    printf("%.12f\n", a[1]);
    return 0;
}
