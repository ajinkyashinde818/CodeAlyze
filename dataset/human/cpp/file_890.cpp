#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll R, G, B, N;
    cin >> R >> G >> B >> N;

    ll ans = 0;
    for (ll r = 0; r <= N; r++) {
        for (ll g = 0; g <= N; g++) {
            ll rem = N - r * R - g * G;
            if (rem < 0) {
                g = N;
            } else if (rem % B == 0) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}
