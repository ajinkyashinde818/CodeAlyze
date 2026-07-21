#include <iostream>

using namespace std;

typedef long long ll;

int main(void)
{
    ll R, G, B, N;
    cin >> R >> G >> B >> N;
    ll ans = 0;
    for (ll x = 0; R * x <= N; x++) {
        for (ll y = 0; R * x + G * y <= N; y++) {
            if ((N - R * x - G * y) % B == 0) {
                ans += 1;
            }
        }
    }
    cout << ans << endl;
}
