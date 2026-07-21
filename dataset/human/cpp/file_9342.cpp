#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool Solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    for (int i = 0; i + m <= n; ++i)
        for (int j = 0; j + m <= n; ++j) {
            bool flag = true;
            for (int y = 0; y < m; ++y)
                for (int x = 0; x < m; ++x)
                    if (a[i + y][j + x] != b[y][x]) flag = false;
            if (flag) return true;
        }

    return false;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cout << (Solve() ? "Yes" : "No") << endl;

    return 0;
}
