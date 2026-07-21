#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    vector<long long> S(N+1, 0);
    for (int i = 0; i < N; i++)
    {
        S[i+1] = S[i] + a[i];
    }
    long long ans;
    ans = LONG_LONG_MAX;
    for (int i = 1; i < N; i++)
    {
        ans = min(ans, abs(S[N] - 2 * S[i]));
    }
    
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
