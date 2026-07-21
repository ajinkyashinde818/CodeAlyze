#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 100;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    for(int i = 0; i <= n; i += r) {
        for(int j = 0; i + j <= n; j += g) {
            int k = n - i - j;
            if(k%b == 0) ans++;
        }
    }
    cout << ans;
    return 0;
}
