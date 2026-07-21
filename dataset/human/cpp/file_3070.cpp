#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N;
    cin >> N;
    vector<ll> a(N + 1);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<vector<ll> > dp(2, vector<ll>(N + 2));
    dp[0][0] = 0;
    dp[1][0] = -LINF;
    for (int i = 0; i <= N; i++) {
        dp[0][i + 1] = max(dp[0][i] + a[i], dp[1][i] - a[i]);
        dp[1][i + 1] = max(dp[0][i] - a[i], dp[1][i] + a[i]);
    }
    cout << dp[0][N] << '\n';
}
