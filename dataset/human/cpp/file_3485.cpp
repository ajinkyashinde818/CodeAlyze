#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int cnt = 0; long long ans = 0;
    long long mini = 1e9;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i]);
        mini = min(mini, abs(a[i]));
        if (a[i] < 0) cnt++;
    }
    if (cnt & 1) {
        ans -= mini * 2;
    }
    cout << ans << endl;
    return 0;
}
