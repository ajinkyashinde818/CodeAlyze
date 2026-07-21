#include <bits/stdc++.h>
using namespace std;

int main( )
{
    int n, m, i, j, k;
    cin >> n >> m;
    string A[55], B[55];
    for (i = 1; i <= n; i++) {
        cin >> A[i];
        A[i] = "#" + A[i];
    }
    for (i = 1; i <= m; i++) {
        cin >> B[i];
        B[i] = "#" + B[i];
    }
    for (i = 1; i + m - 1 <= n; i++) {
        for (j = 1; j + m - 1 <= n; j++) {
            int fl = 1;
            //cout << i << '-' << j << '\n';
            for (k = 1; k <= m; k++) {
                string s = "#" + A[i + k - 1].substr(j, m);
                //cout << s << ' ' << B[k] << '\n';
                if (s != B[k]) {
                    fl = 0;
                    break;
                }
            }
            if (fl) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}
