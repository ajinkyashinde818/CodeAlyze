#include <bits/stdc++.h>
using namespace std;
int main() {
    int ans;
    int r, g, b, n; cin >> r >> g >> b >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if ((n-i*r-j*b) >= 0 && (n-i*r-j*b) % g == 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
