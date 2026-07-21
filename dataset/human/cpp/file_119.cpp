#include <bits/stdc++.h>
using namespace std;

int main(){
    int r, g, b, n; cin >> r >> g >> b >> n;
    int64_t ans = 0;
    for (auto i = 0; i <= n; i++) {
        if(r * i > n) break;
        for (auto j = 0; j <= n; j++) {
            if(r * i + g * j > n) break;
            if((n - r * i - g * j) % b == 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
