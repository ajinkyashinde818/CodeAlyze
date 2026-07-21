#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string a;
    string b;
    a = "";
    b = "";
    for (int i = 0 ; i < n; ++i) {
        string ai;
        cin >> ai;
        a += ai;
    }
    for (int i = 0; i < m; ++i) {
        string bi;
        cin >> bi;
        b += bi;
    }
    string ans = "No";
    for (int i=0; i <= n-m; ++i) {
        for (int j=0; j <= n-m; ++j) {
            for (int p=0; p < m; ++p) {
                for (int q=0; q < m; ++q) {
                    if (a[i * n + j + p * n + q] != b[p*m + q]) {
                        goto out;
                    }
                }
            }
            ans = "Yes";
            goto out2;
            out: ;
        }
    }
out2:
    cout << ans;



}

int main() {

    solve();
    return 0;
}
