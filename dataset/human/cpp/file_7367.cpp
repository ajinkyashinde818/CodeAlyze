#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        ll p;
        cin >> p;
        sum += p;
        a[i] = p;
    }
    ll ans = 9009009009009009009;
    ll now = 0;
    for (int j = 0; j < n - 1; ++j) {
        now += a[j];
        ans = min(ans, abs(2 * now - sum));
    }
    cout << ans << endl;
}
