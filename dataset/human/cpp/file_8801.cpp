#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    char a[n][n], b[m][m];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) cin >> b[i][j];
    bool ans = false;
    for (int i = 0; i <= n - m; i++) for (int j = 0; j <= n - m; j++) {
        bool ok = true;
        for (int ni = 0; ni < m; ni++) for (int nj = 0; nj < m; nj++) {
            if (b[ni][nj] != a[i + ni][j + nj]) ok = false;
        }
        if (ok) {
            ans = true;
            break;
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
