#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int r, g, b, n; cin >> r >> g >> b >> n;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int k = n - r * i - g * j;
            if (k >= 0 && k % b == 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
