#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int r, g, b, n;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> r >> g >> b >> n;
    ll ans = 0;
    for(int i = 0; ;i++) {
        if(i * r > n) break ;
        for(int j = 0; ;j++) {
            if(i * r + j * g > n) break ;
            int tot = n - i * r - j * g;
            if(tot % b == 0) ans++;
        }
    }
    cout << ans;
    return 0;
}
