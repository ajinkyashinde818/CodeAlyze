#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;

int main() {
    int n;  cin >> n;
    ll *a = new ll[n];
    ll sum = 0, x = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    ll ans = LLONG_MAX;
    for (int i = 0; i < n-1; i++) {
        x += a[i];
        ans = min(ans, abs(sum - 2*x));
    }

    cout << ans << endl;

    return 0;
}
