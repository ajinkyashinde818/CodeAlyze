#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>

using namespace std;
using ll = long long int;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    ll X = 0LL;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        X += (long)a[i];
    }

    ll ans = LLONG_MAX;
    ll stmp = 0LL;
    for (int i = 0; i < n-1; ++i) {
        stmp += (long)a[i];
        ll tmp = abs(X - (2 * stmp));
        if (tmp < ans) ans = tmp;
    }

    cout << ans << endl;

    return 0;
}
