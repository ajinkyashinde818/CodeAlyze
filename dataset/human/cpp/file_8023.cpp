/**
 *    author:  FromDihPout
 *    created: 2020-08-01
**/

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<long long> pref(n), suff(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i-1] + a[i];
    }
    suff[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--) {
        suff[i] = suff[i+1] + a[i];
    }
    
    long long ans = INF;
    for (int i = 0; i < n-1; i++) {
        ans = min(ans, abs(pref[i] - suff[i+1]));
    }
    cout << ans << '\n';
    return 0;
}
