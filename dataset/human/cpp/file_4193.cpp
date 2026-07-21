#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
double dist(int x1, int y1, int x2, int y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}
typedef pair<int, double> P;
vector<P> G[1010];
double d[1010];
int V;
void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d + V + 1, INF2);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++){
            P e = G[v][i];
            if (d[e.first] > d[v] + e.second) {
                d[e.first] = d[v] + e.second;
                que.push(P(d[e.first], e.first));
            }
        }
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    int n; cin >> n;
    int x[1010], y[1010], r[1010];
    x[0] = xs, y[0] = ys, r[0] = 0;
    rep(i, n) {
        cin >> x[i + 1] >> y[i + 1] >> r[i + 1];
    }
    x[n + 1] = xt, y[n + 1] = yt, r[n + 1] = 0;
    rep(i, n + 2) {
        rep(j, n + 2) {
            if( i == j) continue;
            double tmpd = dist(x[i], y[i], x[j], y[j]) - r[i] - r[j];
            tmpd = max(0.0, tmpd);
            G[i].push_back({j, tmpd});
            G[j].push_back({i, tmpd});
        }
    }
    V = n + 2;
    dijkstra(0);
    cout << fixed << setprecision(12) << d[n + 1] << endl;

    return 0;
}
