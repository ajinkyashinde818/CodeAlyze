#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int j = 0; j < m; ++j) cin >> b[j];
    
    auto check = [&](int x, int y) {
        vector<string> s(m);
        for (int i = 0; i < m; ++i) {
            s[i] = a[x + i].substr(y, m);
        }
        return s == b;
    };
    
    for (int i = 0; i <= n - m; ++i) {
        for (int j = 0; j <= n - m; ++j) {
            if (check(i, j)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
