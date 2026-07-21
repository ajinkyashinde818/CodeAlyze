#include <iostream>
#include <vector>
const int N_MAX = 1e5 + 10;

typedef long long ll;

using namespace std;

ll dp[N_MAX][2] = {0};
int A[N_MAX];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    dp[0][0] = A[0];
    dp[0][1] = -A[0];
    for (int i = 1; i < N - 1; i++) {
        dp[i][0] = max(dp[i - 1][0] + A[i], dp[i - 1][1] - A[i]);
        dp[i][1] = max(dp[i - 1][0] - A[i], dp[i - 1][1] + A[i]);

        // cout << dp[i][0] << " " << dp[i][1] << endl;
    }

    cout << max(dp[N - 2][0] + A[N - 1], dp[N - 2][1] - A[N - 1]) << endl;
}
