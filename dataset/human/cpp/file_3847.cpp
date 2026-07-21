#include <bits/stdc++.h>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;

constexpr long double INF = 1e20;
constexpr int MAX_N = 2000;

vector<long double> d(MAX_N, INF);
priority_queue<pair<long double, ll>, vector<pair<long double, ll>>, greater<pair<long double, ll>>> que;
vector<vector<pair<ll, long double>>> edges(MAX_N);

struct Point {
    Pll pos;
    long double r;
    Point(ll x=0, ll y=0, long double r=0.0): r(r) {
        pos = {x, y};
    }
    Point operator - (const Point &p) const { return Point(pos.first-p.pos.first, pos.second-p.pos.second); }
    long double abs() const { return sqrt(norm()); }
    long double norm() const { return pos.first*pos.first + pos.second*pos.second; }
    long double dot(Point &p) const { return pos.first*p.pos.first + pos.second*p.pos.second; }
};

void dijkstra(ll start){
    d[start] = 0;
    que.push({0, start});

    while(!que.empty()){
        auto v = que.top(); que.pop();
        if(d[v.second] < v.first) continue;
        for(auto e: edges[v.second]){
            if(d[e.first] > d[v.second] + e.second){
                d[e.first] = d[v.second] + e.second;
                que.push({d[e.first], e.first});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Point s, t;
    cin >> s.pos.first >> s.pos.second >> t.pos.first >> t.pos.second;
    int n;
    cin >> n;
    vector<Point> points(n);
    for(int i=0;i<n;++i){
        cin >> points[i].pos.first >> points[i].pos.second >> points[i].r;
    }

    for(int i=0;i<n;++i) {
        for(int j=i+1;j<n;++j) {
            long double dist = max(0.0L, (points[i]-points[j]).abs() - points[i].r - points[j].r);
            edges[i].emplace_back(j, dist);
            edges[j].emplace_back(i, dist);
        }
        edges[n].emplace_back(i, max(0.0L, (points[i]-s).abs() - points[i].r));
        edges[i].emplace_back(n+1, max(0.0L, (points[i]-t).abs() - points[i].r));
    }
    edges[n].emplace_back(n+1, max(0.0L, (t-s).abs()));

    dijkstra(n);

    cout << fixed << setprecision(15) << d[n+1] << endl;
}
