#include <bits/stdc++.h>
using namespace std;

double g[1002][1002];

int main() {
    int xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    int n;
    cin >> n;
    vector<int> x(n + 2), y(n + 2), r(n + 2);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    x[n] = xs;
    y[n] = ys;
    r[n] = 0;
    x[n + 1] = xt;
    y[n + 1] = yt;
    r[n + 1] = 0;
    n += 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = max(0.0, hypot(x[j] - x[i], y[j] - y[i]) - (r[i] + r[j]));
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    printf("%.20f\n", g[n - 2][n - 1]);
}
