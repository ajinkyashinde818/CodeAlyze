#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    long long ans = 0;
    for (int i = 0; i <= N / R; ++i)
        for (int j = 0; j <= N / G; ++j) {
            int x = N - R * i - G * j;
            if (x >= 0 && x % B == 0)
                ++ans;
        }
    cout << ans << endl;
}
