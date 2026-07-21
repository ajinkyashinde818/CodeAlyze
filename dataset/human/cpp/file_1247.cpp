//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int t = n - i * r - j * g;
            if (t >= 0 && t % b == 0) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
