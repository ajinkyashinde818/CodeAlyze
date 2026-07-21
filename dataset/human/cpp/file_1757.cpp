#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> vis(n, 0);
    vector<int> v(m);
    for (int i = 0; i < m; ++i) {
        cin >> v[i];
        --v[i];
    }
    for (int i = m - 1; i >= 0; --i) {
        if (!vis[v[i]]) {
            cout << (v[i] + 1) << "\n";
            vis[v[i]] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            cout << (i + 1) << "\n";
        }
    }
    return 0;
}
