#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
    int n; cin >> n;

    bool modd = false, zero = false;
    ll sum = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) {modd = !modd; a[i] *= -1;}
        if (a[i] == 0) zero = true;
        sum += a[i];
    }

    ll ans = sum;
    if (modd && !zero) ans -= *min_element(a.begin(), a.end()) * 2;

    cout << ans << endl;
    return 0;
}
