#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2000;

long double x[N], y[N], r[N];
long double a[N][N];

long double dist(long double x1, long double y1, long double x2, long double y2) {
    return sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> x[0] >> y[0] >> x[1] >> y[1];
    int n;
    cin >> n;
    for (int i = 2; i < n + 2; ++i) {
        cin >> x[i] >> y[i] >> r[i];
    }
    for (int i = 0; i < n + 2; ++i) {
        for (int j = 0; j < n + 2; ++j) {
            a[i][j] = max(0.0L, dist(x[i], y[i], x[j], y[j]) - r[i] - r[j]);
        }
    }
    vector<long double> d(n + 2, 1e10);
    d[0] = 0;
    set<pair<long double, int>> q;
    q.insert({ 0, 0 });
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (int j = 0; j < n + 2; ++j) {
            if (d[v] + a[v][j] < d[j]) {
                q.erase({ d[j], j });
                d[j] = d[v] + a[v][j];
                q.insert({ d[j], j });
            }
        }
    }
    cout << fixed << setprecision(30) << d[1];
    return 0;
}
