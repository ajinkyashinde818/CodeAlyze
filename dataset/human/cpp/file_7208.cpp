#include <iostream>
#include <cstdlib>
typedef long long ll;
using namespace std;

int main(void) {
    int N;cin>>N;
    ll dp[N+1];
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        ll a;cin>>a;
        dp[i] = dp[i - 1] + a;
    }
    ll mi = -1;
    for (int i = 1; i <= N - 1; i++) {
        ll x = dp[i];
        ll y = dp[N] - dp[i];
        ll cur = abs(x - y);
        if (mi > cur || mi == -1) mi = cur;
    }
    cout << mi << endl;

    return 0;
}
