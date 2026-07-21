#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> b.at(i);
    }

    for (int top = 0; top <= n - m; top++) {
        for (int left = 0; left <= n - m; left++) {
            bool ok = true;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    if (a.at(i + top).at(j + left) != b.at(i).at(j)) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (ok) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
