#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++ ) cin >> a[i];

    vector<ll> sum(n);
    sum[0] = a[0];
    for (int i = 0; i < n - 1; i++) {
        sum[i + 1] = sum[i] + a[i + 1];
    }

    ll ans = 2 * 1e9 + 1;
    for (int i = 0; i < n - 1; i++) {
        ans = min(ans, llabs(2 * sum[i] - sum[n - 1]));
    }
    cout << ans << endl;
}
