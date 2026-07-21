#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main() {
    int n;
    cin >> n;
    ll a[n];
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    ll x = a[0];
    ll y = total - x;
    ll ans = labs(x - y);
    for (int i = 1; i < n - 1; i++) {
        x += a[i];
        y = total - x;
        ans = min(ans, (ll)labs(x - y));
    }




    cout << ans << endl;
    return 0;
}
