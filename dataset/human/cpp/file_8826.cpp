#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string a[n];
    string b[m];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    for (int i = 0; i < n - m + 1; i++) {
        for (int j = 0; j < n - m + 1; j++) {
            size_t idx = a[i].find(b[0], j);
            if (idx == string::npos) continue;

            bool flag = true;
            for (int k = 1; k < m; k++) {
                if (a[i+k].find(b[k], j) != idx) {
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
