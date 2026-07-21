#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll R, G, B, N;
    cin >> R >> G >> B >> N;

    ll ans = 0;
    for (int i = 0; i <= 3000; ++i) {
        for (int j = 0; j <= 3000; ++j) {
            if (ceil((double)(N - (i * R + j * G)) / B) == floor((double)(N - (i * R + j * G)) / B) and (1.0 * N - (i * R + j * G)) / B >= 0)
                ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
