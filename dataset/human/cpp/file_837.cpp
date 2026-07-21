#include<iostream>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll R, G, B, N;
    cin >> R >> G >> B >> N;
    ll ans = 0;
    for (ll i = 0; i <= 3000; i++) {
        for (ll j = 0; j <= 3000; j++) {
            if (R * i + G * j > N) continue;
            if ((N - (R * i + G * j)) % B == 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
