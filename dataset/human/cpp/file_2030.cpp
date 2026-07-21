#include<iostream>
#include<vector>
#include<algorithm>

using ll = long long;
using namespace std;

int main(void) {

    int N;
    cin >> N;

    vector<ll> A(N);
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<vector<ll>> dp(N+1, vector<ll>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = -1e15;

    for (int i = 0; i < N; ++i) {
        dp[i+1][0] = max({dp[i][0]+A[i], dp[i][1]-A[i]});
        dp[i+1][1] = max({dp[i][0]-A[i], dp[i][1]+A[i]});
    }

    cout << dp[N][0] << endl;
    return 0;
}
