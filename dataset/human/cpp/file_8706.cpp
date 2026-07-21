#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    string ans = "No";
    for (int sw = 0; sw <= n - m; sw++) {
        for (int sh = 0; sh <= n - m; sh++) {
            bool ng = false;
            for (int w = 0; w < m; w++) {
                for (int h = 0; h < m; h++) {
                    if (a[sw + w][sh + h] != b[w][h]) {
                        ng = true;
                        break;
                    }
                    if (ng) break;
                    if (w == m - 1) ans = "Yes";
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
