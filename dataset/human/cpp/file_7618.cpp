#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long int a[n], l[n+1] = {0}, r[n+1] = {0};
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        l[i+1] = l[i] + a[i];
    }
    for(int i = n-1; i >= 0; --i) r[i] = r[i+1] + a[i];
    long long int ans = 200000000000000;
    for(int i = 1; i < n; ++i) ans = min(ans, abs(l[i] - r[i]));
    cout << ans << '\n';

    return 0;
}
