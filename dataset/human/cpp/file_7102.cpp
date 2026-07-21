#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;

int n, a[N], b[N];

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    
    int j = 0, bef = -1;
    for (int i = 0; i < n; i++) {
        if (bef != a[i]) j = 0; 
        if (a[i] == b[i]) {
            for (; j < n; j++) {
                if (a[j] != a[i] && b[j] != a[i]) {
                    swap(b[i], b[j]);
                    break;
                }
            }
            if (a[i] == b[i]) {
                cout << "No";
                return 0;
            }
        }
        bef = a[i];
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << b[i];
    }
}
