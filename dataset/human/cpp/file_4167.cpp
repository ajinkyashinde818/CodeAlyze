// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;
#define double long double
const double eps = 1e-15;
const int N = (int) 1005, mod = (int) 0;
double d[N], adj[N][N];
double dist(int x, int y) { return sqrt(x * 1ll * x + y * 1ll * y); }
int mark[N], x[N], y[N], r[N];
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    int n;
    cin >> n;
    int src = n, snk = n + 1;
    n += 2;
    x[src] = xs;
    y[src] = ys;
    x[snk] = xt;
    y[snk] = yt;
    for (int i = 0; i < n - 2; ++i) {
        cin >> x[i] >> y[i] >> r[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) if (i != j) {
            adj[i][j] = max((double) 0, dist(x[i] - x[j], y[i] - y[j]) - r[i] - r[j]);
        }
    }
    for (int i = 0; i < n; ++i) d[i] = 1e18;
    d[src] = 0;
    for (int rep = 0; rep < n; ++rep) {
        double mn = 1e18;
        int ind = 0;
        for (int j = 0; j < n; ++j) if (!mark[j]) {
            if (d[j] < mn) {
                mn = d[j];
                ind = j;
            }
        }
        mark[ind] = 1;
        for (int j = 0; j < n; ++j)
            if (!mark[j])
                d[j] = min(d[j], d[ind] + adj[ind][j]);
    }
    cout << setprecision(10) << fixed << d[snk] << endl;
}
