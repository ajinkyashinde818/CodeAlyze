#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

void main_()
{
    ll R, G, B, N;
    cin >> R >> G >> B >> N;

    ll ans = 0;
    for (ll r = 0; r <= N; ++r) {
        for (ll g = 0; g <= N; ++g) {
            auto remain = (N - R * r - G * g);
            if (remain >= 0 && remain % B == 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    main_();
    return 0;
}
