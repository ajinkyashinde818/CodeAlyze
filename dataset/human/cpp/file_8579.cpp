#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Welcome to my source code!

const int MAX = 50;

int n, m;
char a[MAX + 1][MAX + 1], b[MAX + 1][MAX + 1];

bool f(int i, int j) {
    bool match = true;
    int x = i + m - 1, y = j + m - 1;
    for (int k = 0; i <= x; i++, k++) {
        for (int t = 0, nj = j; nj <= y; nj++, t++) {
            if (a[i][nj] != b[k][t]) match = false;
        }
    }
    return match;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) cin >> b[i][j];
    bool flag = false;
    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= n - m; j++) {
            if (f(i, j)) flag = true;
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}
