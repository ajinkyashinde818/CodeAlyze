#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


int main() {

    long long N;

    cin >> N;
    vector<vector<long long> > dp(100010, vector<long long> (2,0));
    vector<long long> A(N);

    for (long long i = 0;i < N; i++){
        cin >> A[i];
    }
    dp[0][0] = 0;
    dp[0][1] = -1145141919810;
    for (long long i = 0;i < N; i++){
        dp[i + 1][0] = max(dp[i][0] + A[i], dp[i][1] - A[i]);
        dp[i + 1][1] = max(dp[i][0] - A[i], dp[i][1] + A[i]);
    }
    cout << dp[N][0] << endl;
}
