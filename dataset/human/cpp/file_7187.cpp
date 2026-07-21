#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int64_t> a(n), b(n);
    for(auto& e : a) cin >> e;
    partial_sum(begin(a), end(a), begin(a));
    int64_t ans = 1e16;
    for(int i = 0; i < n - 1; i++){
        ans = min(ans, abs(a[i] - (a[n-1] - a[i])));
    }
    cout << ans << endl;
    return 0;
}
