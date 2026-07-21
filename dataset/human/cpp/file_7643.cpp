#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<long long> sum(N + 1, 0);
    for (int i = 1; i <= N; i++) sum[i] = sum[i - 1] + a[i - 1];

    long long ans = (1LL<<32);
    for (int i = 1; i < N; i++) {
        long long x = sum[i];
        long long y = sum[N] - x;
        ans = min(ans, abs(x - y));
    }

    cout << ans << endl;
}
