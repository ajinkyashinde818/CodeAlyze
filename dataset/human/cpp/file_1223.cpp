#include <iostream>
#include <vector>
#include <string>
using ll = long long;
using namespace std;

int main() {
    ll R, G, B, N;
    cin >> R >> G >> B >> N;
    // r + g + b == N
    // r, g, b >= 0
    ll ans = 0;
    for (int i = 0; i <= N/R; ++i) {
        for (int j = 0; j <= N/G; ++j) {
            int v = N - i * R - j * G;
            if (v >= 0 && v % B == 0)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
