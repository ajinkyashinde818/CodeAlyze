#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<m; ++i) cin >> b[i];
    bool ans = false;
    for (int i=0; i<n-m+1; ++i) {
        for (int j=0; j<n-m+1; ++j) {
            vector<string> copa(m);
            for (int k=0; k<m; ++k) {
                copa[k] = a[i+k].substr(j, m);
            }
            if (copa == b) ans = true;
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
}
