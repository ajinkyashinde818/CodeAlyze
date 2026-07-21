#include <bits/stdc++.h>

using namespace std;

int a[10000001];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    long long sum = 0, sum1 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i < n - 1) {
            sum+=a[i];
        } else {
            sum1+=a[i];
        }
    }
    long long ans = abs(sum-sum1);
    for (int i = n-2; i > 0; --i) {
        sum1+=a[i];
        sum-=a[i];
        ans = min (ans, abs(sum - sum1));
    }
    cout << ans << endl;
    return 0;
}
