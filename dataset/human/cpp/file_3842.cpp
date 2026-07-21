#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<double, ll> P;
struct edge { ll to, cost; };
ll inf = 1e18;

ll xs, ys, xt, yt, n, x[1010], y[1010], r[1010];

vector<P> G[100010];
double d[100010];

void dijkstra(ll s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d + n, inf);
    d[s] = 0;
    que.push(P(0, s));
    
    while (!que.empty()) {
        P p = que.top();  que.pop();
        ll v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++) {
            P e = G[v][i];
            if (d[e.second] > d[v] + e.first) {
                d[e.second] = d[v] + e.first;
                que.push(P(d[e.second], e.second));
            }
        }
    }
}

double expose(int p, int q) {
    return max(0.0, sqrt(pow(x[p] - x[q], 2) + pow(y[p] - y[q], 2)) - r[p] - r[q]);
}

int main() {
    cin >> xs >> ys >> xt >> yt;
    cin >> n;
    x[n] = xs;  y[n] = ys;  r[n] = 0;
    x[n + 1] = xt;  y[n + 1] = yt;  r[n + 1] = 0;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> r[i];

    n += 2;
    //vector<pair<int, double> > G[1010];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            G[i].emplace_back(expose(i, j), j);
            G[j].emplace_back(expose(i, j), i);
            //cout << i << " " << j << " " << expose(i, j) << endl;
        }
    }


    dijkstra(n - 2);
    cout << setprecision(12) << d[n - 1] << endl;

    //for (int i = 0; i < n; i++) cout << i << " " << d[i]  << endl;

}

/* 
g++ -std=c++14 _main.cpp
*/
