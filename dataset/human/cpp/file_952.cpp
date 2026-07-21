#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int ans = 0;
    for (int r = 0; r * R <= N; ++r) {
        for (int g = 0; g * G <= N; ++g) {
            int res = N - r * R - g * G;
            if (res < 0) continue;
            if (res % B) continue;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
