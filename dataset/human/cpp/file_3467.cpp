#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const ll inf = (1LL << 60);
 
int n;
 
ll a[100002], dp[100002][2];
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    cin >> n;
 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    dp[0][0] = a[0];
    dp[0][1] = -inf; //no puedo aplicar la operacion a un solo elemento
    dp[1][0] = a[0] + a[1];
    dp[1][1] = -(a[0] + a[1]);
 
    for(int i = 2; i < n; i++) {
        dp[i][0] = a[i] + a[i - 1] + max(dp[i - 2][0], dp[i - 2][1]);
        dp[i][0] = max(dp[i][0], a[i] + dp[i - 1][1]);
 
        dp[i][1] = -(a[i] + a[i - 1]) + max(dp[i - 2][0], dp[i - 2][1]);
        dp[i][1] = max(dp[i][1], dp[i - 1][1] - a[i] + a[i - 1] * 2);
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
}
