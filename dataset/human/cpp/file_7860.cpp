#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cmath>
#include <climits>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)
#define all(v) v.begin(),v.end()

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> cum(n);
    ll sum = 0;
    rep(i,n) {
        cin >> a[i];
        sum += a[i];
        if (i > 0) cum[i] = cum[i-1]+a[i];
        else cum[i] = a[i];
    }
    ll ans = LLONG_MAX;
    rep(i,n-1) {
        ll x = cum[i];
        ll y = sum-x;
        ans = min(ans, abs(x-y));
    }
    cout << ans << endl;
    return 0;
}
