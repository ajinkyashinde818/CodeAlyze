#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll inf = 1LL<<60;
const double eps = 1e-9;

typedef pair<ll, ll> P;
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    int n, m;
    cin >> n >> m;

    vector <string> a(n), b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    bool ok;

    for (int i = 0; i < (n-m)+1; i++) {
        for (int j = 0; j < (n-m)+1; j++) {
            bool ok = true;
            for (int k = 0; k < m; k++) {
                for (int l = 0; l < m; l++) {
                    if (a[i+k][j+l] != b[k][l]) {
                        ok = false;
                    }
                }
            }
            if (ok) {
                cout << "Yes" << endl;
                return 0;
            } 
        }
    }
    cout << "No" << endl;
    return 0;
}
