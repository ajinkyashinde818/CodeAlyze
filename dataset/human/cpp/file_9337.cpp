#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for (auto& e : a) cin >> e;
    for (auto& e : b) cin >> e;

    string ans = "No";
    for (int x = 0; x + m <= n; x++) {
        for (int y = 0; y + m <= n; y++) {
            bool same = true;
            for (int dx = 0; dx < m; dx++) {
                for (int dy = 0; dy < m; dy++) {
                    if (a[x+dx][y+dy] != b[dx][dy]) same = false;
                }
            }
            if (same) ans = "Yes";
        }
    }
    cout << ans << endl;
}
