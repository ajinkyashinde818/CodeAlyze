#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for (auto& e : a) cin >> e;
    partial_sum(begin(a), end(a), begin(a));
    int64_t ans = 1e18;
    for (int64_t i = 0; i+1 < n; i++) ans = min(ans, abs((a.back() - a[i]) - a[i]));
    cout << ans << endl;
}
