#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<string> a(n), b(m);
    for (auto i = 0; i < n; i++) cin >> a[i];
    for (auto i = 0; i < m; i++) cin >> b[i];

    for (auto i = 0; i <= (n - m); i++) {
        for (auto j = 0; j <= (n - m); j++) {
            bool flg = true;
            for (auto k = 0; k < m; k++) {
                if(a[i + k].substr(j, m) != b[k]) {
                    flg = false; break;
                }
            }
            if(flg) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
