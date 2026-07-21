#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = (int)1e5 + 100;
ll a[maxN];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(228);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    int cnt = 0;
    ll mn = (ll)1e18;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            cnt ^= 1;
            a[i] = -a[i];
        }
        sum += a[i];
        mn = min(mn, a[i]);
    }
    if (cnt % 2 == 0) {
        cout << sum;
    }
    else {
        cout << sum - 2 * mn;
    }
    return 0;
}
