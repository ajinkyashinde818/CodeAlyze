#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

int main(void) {
    i64 r, g, b, n, ans = 0;
    cin >> r >> g >> b >> n;
    for (i64 i = 0; i <= 3000; i++) {
        for (i64 j = 0; j <= 3000; j++) {
            i64 rem = n - r * i - g * j;
            if (rem >= 0 && rem % b == 0) ans++;
        }
    }
    cout << ans << endl;
}
