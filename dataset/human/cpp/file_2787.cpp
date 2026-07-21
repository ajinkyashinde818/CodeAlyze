#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e12;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    int cnt0 = 0, cnt1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) cnt0++;
        else if (a[i] < 0) cnt1++;
    }

    ll ans = 0;
    if (cnt0 > 0 || cnt1 % 2 == 0) {
        for (int i = 0; i < n; i++) {
            ans += abs(a[i]);
        }
    } else {
        ll minv = INF;
        for (int i = 0; i < n; i++) {
            ans += abs(a[i]);
            minv = min(minv, abs(a[i]));
        } 
        ans += -minv * 2;
    }
    cout << ans << endl;
    return 0;
}
