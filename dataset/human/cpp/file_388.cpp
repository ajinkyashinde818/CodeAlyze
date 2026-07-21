#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    int R, G, B, N; cin >> R >> G >> B >> N;
    int ans = 0;
    for (int r = 0; r <= N; r += R) {
        for (int g = 0; r + g <= N; g += G) {
            int b = N - r - g;
            if (b % B == 0) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
