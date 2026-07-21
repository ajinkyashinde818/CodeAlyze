#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
const double EPS = 1e-15;
using ll = long long;
using ull = unsigned long long;
const int inf = 2e9;
const ll INF = 2e18;
const ll MOD = 1e9+7;
const ll MOD1 = 998244353;
//typedef pair<int,int> P;

#define REP(i,n) for (int i = 0; i < (n); i++)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
//#define mp make_pair

ll dp[100010][2];
ll a[100010];

int main(){
  /**入力**/
  int n;
  cin >> n;
  REP(i,n) {
    cin >> a[i+1];
  }
  REP(i,n+1) REP(j,2) dp[i][j] = -INF;
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = max(dp[i][0], dp[i-1][0] + a[i]);
    dp[i][0] = max(dp[i][0], dp[i-1][1] - a[i]);
    dp[i][1] = max(dp[i][1], dp[i-1][0] - a[i]);
    dp[i][1] = max(dp[i][1], dp[i-1][1] + a[i]);
  }
  cout << dp[n][0] << endl;
  return 0;
}
