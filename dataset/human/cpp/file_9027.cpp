#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int INF = 1 << 29;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<string> b(n);
    for (int i=0; i<m; i++){
        cin >> b[i];
    }
    for (int i=0; i<=n-m; i++){
        for (int j=0; j<=n-m; j++){
            bool matched = true;
            for (int k=0; k<m; k++){
                for (int l=0; l<m; l++){
                    if (a[i+k][j+l] != b[k][l]) {
                        matched = false;
                        break;
                    }
                }
                if (!matched) {
                    break;
                }
            }
            if (matched) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
