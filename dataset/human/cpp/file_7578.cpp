#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long y = 0;
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        y += a.at(i);
    }
    
    long long ans = LONG_LONG_MAX;
    long long x = 0;
    for (int i = 0; i < n - 1; i++) {
        x += a.at(i);
        y -= a.at(i);
        ans = min(ans, abs(x - y));
    }
    cout << ans << endl;
}
