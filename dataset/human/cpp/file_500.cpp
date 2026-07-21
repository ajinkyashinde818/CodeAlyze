#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int R, G, B, n;
    cin >> R >> G >> B >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i + R <= n; i++) dp[i + R] += dp[i];
    for (int i = 0; i + G <= n; i++) dp[i + G] += dp[i];
    for (int i = 0; i + B <= n; i++) dp[i + B] += dp[i];
    cout << dp[n] << endl;
    return 0;
}
