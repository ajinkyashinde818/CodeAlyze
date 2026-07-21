#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, R;
    cin >> N >> R;
    if ( N < 10 ) return R + 100*(10-N);
    else return R;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}
