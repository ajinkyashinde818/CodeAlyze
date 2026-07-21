#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    bool match;
    string ans = "No";
    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= n - m; j++) {
            match = true;
            for (int k = 0; k < m; k++) {
                for (int l = 0; l < m; l++) {
                    if (a[i+k][j+l] != b[k][l]) match = false;
                }
            }
            if (match) ans = "Yes";
        }
    }

    cout << ans << endl;
    
}
