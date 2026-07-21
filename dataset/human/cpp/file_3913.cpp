#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int N;

vector<double> dijkstra(int s, vector<vector<pair<int, double>>> adj) {
    vector<bool> visit(N + 2);
    vector<double> dist(N + 2, 1e12);
    vector<int> par(N + 2);
    priority_queue<pair<double, int>> q;
    dist[s] = 0; q.push(make_pair(0.0, s)); visit[s] = true;
    while (!q.empty()) {
        pair<double, int> tmp = q.top(); q.pop();
        int t = tmp.second; visit[t] = true;
        if (dist[t] < tmp.first * (-1) ) continue;  //別のルートでdist[t]が更新されていれば無視
        for (int i = 0; i < adj[t].size(); i++) {
            int next = adj[t][i].first;
            if (visit[next]) continue;
            if (dist[next] > dist[t] + adj[t][i].second) {
                dist[next] = dist[t] + adj[t][i].second;
                par[next] = t;
                q.push(make_pair(dist[next] * (-1), next));
            }
        }
    }
    return dist;
}

int main() {
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    cin >> N;
    vector<long long> x(N + 2), y(N + 2), r(N + 2);
    x[0] = sx; y[0] = sy; x[N + 1] = tx; y[N + 1] = ty; r[0] = 0; r[N + 1] = 0;
    for (int i = 1; i < N + 1; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    vector<vector<pair<int, double>>> adj(N + 2);
    for (int i = 0; i < N + 2; i++) {
        for (int j = i + 1; j < N + 2; j++) {
            double d = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            adj[i].push_back(make_pair(j, max(0.0, d - r[i] - r[j])));
            adj[j].push_back(make_pair(i, max(0.0, d - r[i] - r[j])));
        }
    }
    vector<double> dist = dijkstra(0, adj);
    cout << setprecision(20) << dist[N + 1] << endl;
}
