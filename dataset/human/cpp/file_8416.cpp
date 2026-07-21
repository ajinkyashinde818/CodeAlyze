#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<string> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    for (int p = 0; p < n - m + 1; ++p) {
        for (int q = 0; q < n - m + 1; ++q) {
            bool flag = true;
            for (int k = 0; k < m; ++k) {
                if (b[k] != a[p + k].substr(q, m)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
