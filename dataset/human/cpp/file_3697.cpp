#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m = 0, mini = 1000000005;
    bool zero = false;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i] < 0) m++;
        else if(a[i] == 0) zero = true;
        mini = min(mini, abs(a[i]));
    }
    long long int ans = 0;
    for(int i = 0; i < n; ++i) ans += max(a[i], -a[i]);
    if(zero) cout << ans << '\n';
    else {
        if(m%2 == 0) cout << ans << '\n';
        else cout << ans - mini*2 << '\n';
    }
    return 0;
}
