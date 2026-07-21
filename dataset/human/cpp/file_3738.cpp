#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int MAX_N = 1e5;
long long dp[MAX_N][2];

int main() {
    int N;
    cin >> N;
    vector<long long> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    dp[0][0] = 0;
    dp[0][1] = -1e6;
    for (int i = 1; i <= N; i++) {
        dp[i][0] = max(dp[i - 1][0] + A[i], dp[i - 1][1] - A[i]);
        dp[i][1] = max(dp[i - 1][0] - A[i], dp[i - 1][1] + A[i]);
    }
    cout << dp[N][0] << endl;
    return 0;
}
