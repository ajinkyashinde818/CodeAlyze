#include <algorithm>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; i++) {
        cin >> a.at(i);
    }
    for (int i=1; i<n; i++) {
        a.at(i) += a.at(i-1);
    }
    ll ans = 1e12;
    for (int i=0; i<n-1; i++) {
        ll buf = abs(a.at(n-1) - 2*a.at(i));
        ans = min(ans, buf);
    }
    cout << ans << endl;
    return 0;
}
