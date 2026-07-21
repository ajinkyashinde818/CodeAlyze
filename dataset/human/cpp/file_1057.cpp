#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int cnt = 0;
    for (int i = 0; r * i <= n; i++) {
        for (int j = 0; b * j <= n - r * i; j++) {
            int k = n - r * i - b * j;
            if (k % g == 0) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
