#include <iostream>
using namespace std;

int main() {
    long long n, c;
    cin >> n >> c;
    long long x[n], v[n], dp[n + 1], result = 0;
    dp[0] = 0;
    for (long long i = 0; cin >> x[i] >> v[i]; i++) {
    }
    for (long long i = 0, sum = 0; i < n; i++) {
        sum += v[i];
        dp[i + 1] = max(dp[i], sum - x[i]);
    }
    result = max(result, dp[n]);
    for (long long i = n - 1, sum = 0; i > 0; i--) {
        sum += v[i];
        result = max(result, sum - 2 * (c - x[i]) + dp[i]);
    }
    dp[n] = 0;
    for (long long i = n - 1, sum = 0; i >= 0; i--) {
        sum += v[i];
        dp[i] = max(dp[i + 1], sum - c + x[i]);
    }
    result = max(result, dp[0]);
    for (long long i = 0, sum = 0; i < n; i++) {
        sum += v[i];
        result = max(result, sum - 2 * x[i] + dp[i + 1]);
    }
    cout << result;
    return 0;
}
