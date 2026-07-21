#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    vector<vector<ll>> dp(N, vector<ll>(2, -1e18));
    dp[0][0] = 0;
    for (int i = 0; i < N - 1; ++i) {
        dp[i + 1][0] = max(dp[i][0] + A[i], dp[i][1] - A[i]);
        dp[i + 1][1] = max(dp[i][0] - A[i], dp[i][1] + A[i]);
    }

    ll ans = max(dp[N - 1][0] + A[N - 1], dp[N - 1][1] - A[N - 1]);
    cout << ans << endl;

    return 0;
}
