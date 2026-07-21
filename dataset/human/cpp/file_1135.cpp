#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, g, b, n; cin >> r >> g >> b >> n;
    int ans = 0;
    for(int i = 0; i <= 3000; ++i) {
        for(int j = 0; j <= 3000; ++j) {
            const int m = n - i * r - j * g;
            if(m >= 0 && m % b == 0) {
                ans += 1;
            }
        }
    }
    cout << ans << endl;
}
