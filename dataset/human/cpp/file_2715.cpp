#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ll n;   cin >> n;
    ll *a = new ll[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll cnt = (a[0] < 0) ? 1 : 0;

    ll ans = abs(a[0]), m = abs(a[0]);
    for (int i = 1; i < n; i++) {
        if (abs(a[i]) < m)
            m = abs(a[i]);
        ans += abs(a[i]);
        if (a[i] < 0)
            cnt++;
    }

    if (cnt%2)
        cout << ans - 2*m << endl;
    else 
        cout << ans << endl;

    return 0;
}
