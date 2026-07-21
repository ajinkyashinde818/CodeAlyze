#include <bits/stdc++.h>
using namespace std;
 
int n, m;
string a[60], b[60];
 
int match(int x, int y) {
    // 与えられた開始地点から、画素を比較するループ
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (a[x+i][y+j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}
 
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
 
    // 開始地点を探るループ
    for (int i = 0; i <= n-m; i++) {
        for (int j = 0; j <= n-m; j++) {
            if (match(i, j) == true) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
 
    cout << "No" << endl;
 
    return 0;
}
