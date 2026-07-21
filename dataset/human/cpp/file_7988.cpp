#include <bits/stdc++.h>
using namespace std;

const long long inf = (long long)1e16;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector <long long> A(n);
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        sum += A[i];
    }
    long long ans = inf;
    long long cnt = 0;
    for(int i = 0; i < n - 1; i++) {
        cnt += A[i];
        ans = min(ans, abs((sum - cnt) - cnt));
    }
    cout << ans;

    return 0;
}
