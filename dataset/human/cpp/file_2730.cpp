#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX = 100010;

int N;
ll A[MAX];
ll dp[MAX][2];

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    
    dp[0][0] = 0;
    dp[0][1] = -1e18;
    
    for (int i=0; i<N; i++) {
        dp[i+1][0] = max(dp[i][0]+A[i], dp[i][1]-A[i]);
        dp[i+1][1] = max(dp[i][0]-A[i], dp[i][1]+A[i]);                
    }

    cout << dp[N][0] << endl;
}
