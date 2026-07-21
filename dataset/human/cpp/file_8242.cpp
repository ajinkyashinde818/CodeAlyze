#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int64_t> sunuke(n);
    vector<int64_t> arai(n);
    int64_t sum = 0;
    for (auto i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        sunuke[i] = sum;
    }
    sum = 0;
    for (auto i = n - 1; i >= 0; i--) {
        sum += a[i];
        arai[i] = sum;
    }

    int64_t ans = INT_MAX;
    for (auto i = 0; i < n - 1; i++) {
        // cout << sunuke[i] << " " << arai[i + 1] << endl;
        ans = min(ans, abs(sunuke[i] - arai[i + 1]));
    }

    cout << ans << endl;
    return 0;
}
