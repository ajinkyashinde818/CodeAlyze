#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, g, b, n, ans = 0;
    cin >> r >> g >> b >> n;

    for (int i = 0; i * r <= n; i++)
        for (int j = 0; j * g + i * r <= n; j++) {
            int left = n - i * r - j * g;
            ans += (left % b == 0);
        }
    cout << ans << '\n';
}
