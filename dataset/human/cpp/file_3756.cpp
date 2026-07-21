#include <bits/stdc++.h>
using namespace std;
int main()
{
    int xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;
    int N; cin >> N;
    vector<int> X(N+2), Y(N+2), R(N+2);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i] >> R[i];
    X[N] = xs, Y[N] = ys; R[N] = 0;
    X[N+1] = xt, Y[N+1] = yt, R[N+1] = 0;
    vector<vector<double>> cost(N+2, vector<double>(N+2));
    for (int i = 0; i < N+2; i++) {
        for (int j = 0; j < N+2; j++) {
            cost[i][j] = max(0.0, sqrt(pow(X[i]-X[j],2)+pow(Y[i]-Y[j],2))-R[i]-R[j]);
        }
    }
    vector<double> dist(N+2, 1e20); dist[N] = 0;
    using P = pair<double, int>;
    priority_queue<P, vector<P>, greater<P>> Q;
    Q.push(make_pair(0, N));
    while (!Q.empty()) {
        P p = Q.top();
        Q.pop();
        if (p.first != dist[p.second]) continue;
        if (p.second == N+1) {
            cout << fixed << setprecision(16) << p.first << endl;
            break;
        }
        for (int i = 0; i < N+2; i++) {
            double d = p.first + cost[p.second][i];
            if (d < dist[i]) {
                dist[i] = d;
                Q.push(make_pair(d, i));
            }
        }
    }
    return 0;
}
