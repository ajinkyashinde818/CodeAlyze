#include<iostream>
using namespace std;


long long A[100000];
int N;
long long dp[100001][2];
// dp[i][0] := A[i]とA[i+1]に-1をかけなかった場合のA[0: i + 1)の和の最大値
// dp[0][0] = A[0], dp[0][1] = -A[0]
// dp[i + 1][0] = max(dp[i][0] + A[i + 1], dp[i][1] - A[i + 1])
// 答えはdp[N-1][0] + A[N - 1], dp[N-1][1] - A[N - 1]

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    dp[0][0] = A[0];
    dp[0][1] = -A[0];
    for(int i = 0; i + 1 < N - 1; i++){
        dp[i + 1][0] =
            max(dp[i][0] + A[i + 1],
                dp[i][1] - A[i + 1]);
        dp[i + 1][1] =
            max(dp[i][0] - A[i + 1],
                dp[i][1] + A[i + 1]);
    }
    cout << max(dp[N - 2][0] + A[N - 1], dp[N - 2][1] - A[N - 1]) << endl;
}
