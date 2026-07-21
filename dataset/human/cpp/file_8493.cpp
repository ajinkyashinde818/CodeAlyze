#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char a[n][n];
    char b[m][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }    
    bool match = true;
    int count;
    for (int ax = 0; ax < n-m+1; ax++) {
        for (int ay = 0; ay < n-m+1; ay++) {
            count = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i+ax][j+ay] != b[i][j]) {
                        i = m;
                        j = m;
                    } else {
                        count++;
                    }
                }
            }
            if (count == m*m) {
                cout << "Yes\n";
                ax = n-m+1;
                ay = n-m+1;
            }
        }
    }
    if (count != m*m) cout << "No\n";
}
