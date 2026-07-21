#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;


long long dp[2][100010];

int main() {
    int N; cin >> N;

    // init
    for (int i=0; i<2; i++) {
        for (int j=0; j<100010; j++) {
            dp[i][j] = LLONG_MIN / 3;
        }
    }

    vector<long long> v;
    for (int i=0; i<N; i++) {
        long long a; cin >> a;
        v.push_back(a);
    }

    dp[0][0] = 0;
    for (int i=1; i<N; i++) {  // 1base
        long long A = v[i-1];

        // v[i]を反転させない
        dp[0][i] = max(dp[0][i], dp[0][i-1] + A);
        dp[0][i] = max(dp[0][i], dp[1][i-1] - A);

        // v[i]を反転させる
        dp[1][i] = max(dp[1][i], dp[0][i-1] - A);
        dp[1][i] = max(dp[1][i], dp[1][i-1] + A);
    }

    long long a = dp[0][N-1] + v[N-1];
    long long b = dp[1][N-1] - v[N-1];
    cout << max(a,b) << endl;


    return 0;
}
