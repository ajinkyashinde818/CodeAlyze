#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll N; cin >> N;
    vector<ll> v(N); 
    ll minus_count = 0;
    ll abs_min = MOD;
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        if (abs_min > abs(v[i])) abs_min = abs(v[i]);
        if (v[i] < 0) ++minus_count;
        ans += abs(v[i]);
    }
    if (minus_count % 2 == 1) ans -= 2 * abs_min;
    cout << ans << endl;
}
