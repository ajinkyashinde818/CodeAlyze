#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m;
    vector<string> a, b;
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= n - m; j++) {
            bool flag = true;
            for (int k = 0; k < m; k++) {
                if (!equal(b[k].begin(), b[k].end(), a[i + k].begin() + j)) {
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
}
