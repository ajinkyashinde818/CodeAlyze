#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
using namespace std;
 
long long A[100000];
long long dp[100000][2];
int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    dp[0][0] = A[0] + A[1];
    dp[0][1] = - A[0] - A[1];
    for(int i = 1; i < N - 1; i++){
        dp[i][0] = max(dp[i - 1][0] + A[i + 1], 
                        dp[i - 1][1] + A[i + 1]);
        dp[i][1] = max(dp[i - 1][0] - 2 * A[i] - A[i + 1],
                        dp[i - 1][1] + 2 * A[i] - A[i + 1]);
    }
    cout << max(dp[N - 2][0], dp[N - 2][1]) << endl;
    return 0;
}
