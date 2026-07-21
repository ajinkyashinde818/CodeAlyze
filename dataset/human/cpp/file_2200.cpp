#include <bits/stdc++.h>
using namespace std;

int n;
const int maxn = 1e5 + 500;
long long dp[maxn][2];
int a[maxn];

long long solve (int p, bool flip) {
  if (p >= n) return 0;
  if (dp[p][flip] != -1) return dp[p][flip];
  long long tot = - 1e12; 
  if (flip == false) {    
    tot = max(tot, a[p] + solve(p + 1, false));
    if (p <= n - 2) tot = max(tot, -a[p] + solve(p + 1, true));
  } else {
    tot = max(tot, -a[p] + solve(p + 1, false));
    if (p <= n - 2) tot = max(tot, a[p] + solve(p + 1, true));
  } 
  return dp[p][flip] = tot;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  memset (dp, -1, sizeof(dp));
  cout << solve (0, 0) << '\n';
  return 0;
}
