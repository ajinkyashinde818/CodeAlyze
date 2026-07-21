#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;

struct pos {
    ll x, y, r;
};

struct edge {
    int to;
    double cost;
};

struct status {
    double cost;
    int v;

    bool operator<(const status &rhs) const { return cost < rhs.cost; };
    bool operator>(const status &rhs) const { return cost > rhs.cost; };
};

const double INF = 1e20;

vector<double> dijkstra(int s, int n, vector<vector<edge>> &graph) {
    priority_queue<status, vector<status>, greater<>> que;
    vector<double> dis(n, INF);
    dis[s] = 0;
    que.push({0, s});

    while (!que.empty()) {
        status now = que.top();
        que.pop();

        if (dis[now.v] < now.cost)continue;

        for (auto next:graph[now.v]) {
            if (dis[next.to] > dis[now.v] + next.cost) {
                dis[next.to] = dis[now.v] + next.cost;
                que.push({dis[next.to], next.to});
            }
        }
    }

    return dis;
}

int main() {
    pos s{0, 0, 0}, t{0, 0, 0};
    cin >> s.x >> s.y >> t.x >> t.y;
    int n;
    cin >> n;
    vector<pos> v(n + 2);
    v[0] = s, v[n + 1] = t;
    for (int i = 1; i <= n; i++) cin >> v[i].x >> v[i].y >> v[i].r;

    vector<vector<edge>> graph(n + 2);
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            ll diffx = v[i].x - v[j].x, diffy = v[i].y - v[j].y;
            graph[i].push_back({j, max(0.0, sqrt(diffx * diffx + diffy * diffy) - v[i].r - v[j].r)});
        }
    }

    cout << fixed << setprecision(15) << dijkstra(0, n + 2, graph)[n + 1] << endl;
    return 0;
}
