#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(2));

    dp[0][0] = a[0];
    dp[0][1] = -1e12;

    for(int i = 1; i < n; i++){
        //-1倍しない場合
        dp[i][0] = a[i] + max(dp[i-1][0], dp[i-1][1]);
        //-1倍する場合
        dp[i][1] = -a[i] + max(dp[i-1][0] - 2*a[i-1], dp[i-1][1] + 2*a[i-1]);
    }

    cout << max(dp[n-1][0], dp[n-1][1]) << endl;
    return 0;
}
