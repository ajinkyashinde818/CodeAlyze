#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    ll x[1003] = {}, y[1003] = {}, r[1003] = {};
    double d[1003] = {};
    bool b[1003] = {};
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
    int n;
    cin >> x[0] >> y[0] >> x[1] >> y[1] >> n;
    x[n + 1] = x[1]; y[n + 1] = y[1];
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i] >> r[i];
    for (int i = 1; i <= n + 1; i++) d[i] = 1ll * mod * mod;
    q.push({0, 0});
    while (!q.empty()) {
        int c = q.top().second;
        q.pop();
        if (b[c]) continue; b[c] = 1;
        for (int i = 0; i <= n + 1; i++) {
            double e = max(0.0, sqrt((x[c] - x[i]) * (x[c] - x[i]) + (y[c] - y[i]) * (y[c] - y[i])) - r[c] - r[i]);
            if (d[i] > d[c] + e + 1e-12) {
                d[i] = d[c] + e;
                q.push({d[i], i});
            }
        }
    }
    cout << setprecision(13) << d[n + 1];
}
