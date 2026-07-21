#include <algorithm>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

typedef long long ll;

int main(void) {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll all = 0;
    for (ll i = 0; i < n; i++) {
        all += a[i];
    }

    ll sum = a[0];
    ll ans = abs(sum - (all - sum));
    for (ll i = 1; i < n - 1; i++) {
        sum += a[i];
        ans = min(ans, abs(sum - (all - sum)));
    }

    cout << ans << endl;

    return 0;
}
