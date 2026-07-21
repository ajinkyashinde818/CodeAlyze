#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
int main() {
    int n, m;
    cin >> n >> m;
    string a[n], b[m];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
 
    bool isContained =  false;
    for (int i = 0; i < n - m + 1; i++) {
        for (int j = 0; j < n - m + 1; j++) {
            bool match = true;
            for (int y = 0; y < m; y++) {
                for (int x = 0; x < m; x++) {
                    if(a[i + y][j + x] != b[y][x]) {
                        match = false;
                    }
                }
            }
            if (match) {
                isContained = true;
            }
        }
    }
 
    if (isContained) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
 
 
    return 0;
}
