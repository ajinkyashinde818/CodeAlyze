#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    long long sum[200001], ans = LLONG_MAX;
    sum[0] = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        sum[i] = sum[i - 1] + a;
    }
    for (int i = 1; i <= n - 1; i++) {
        ans = min(ans, abs(sum[i] - (sum[n] - sum[i])));
    }
    cout << ans << endl;
}
