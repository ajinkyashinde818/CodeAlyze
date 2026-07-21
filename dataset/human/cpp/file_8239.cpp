/**
 * @author torith
 * @date 2018-10-26
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    ll a[200000];
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    ll ans = 1000000000000000000LL;
    ll tmp = 0;
    for (int i = 0; i < N - 1; ++i) {
        tmp += a[i];
        ans = min(ans,abs(sum-2*tmp));
    }

    cout << ans << "\n";

    return 0;
}
