#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007LL;

ll solve() {
    ll N;
    string S;
    cin >> N >> S;
    ll ans = 1;
    for ( int i = 1; i <= N; i++ ) {
        ans = ans * i % MOD;
    }
    ll f = 0;
    for ( char s : S ) {
        bool up = (s == 'B') ^ (f % 2 != 0);
        if ( up ) {
            f++;
        } else {
            ans = ans * f % MOD;
            f--;
        }
    }
    if ( f != 0 ) return 0;
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}
