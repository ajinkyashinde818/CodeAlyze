#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Welcome to my source code!

int main() {
    int n;
    cin >> n;
    int a[n];
    ll raccoon = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        raccoon += a[i];
    }
    ll snuke = 0, ans = 1e15;
    for (int i = 0; i < n - 1; i++) {
        snuke += a[i];
        raccoon -= a[i];
        ans = min(ans, abs(raccoon - snuke));
    }
    cout << ans << endl;
}
