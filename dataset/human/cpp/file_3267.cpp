#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

typedef long long int ll;
 
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<ll> v(n+1);
  for(int i=1; i<n+1; i++)
    cin >> v[i];
  ll dp[100001][2];
  dp[0][0] = 0;
  dp[0][1] = numeric_limits<ll>::min() / 2;
  for(int i=1; i<n+1; i++) {
    dp[i][0] = max(dp[i-1][0]+v[i], dp[i-1][1]-v[i]);
    dp[i][1] = max(dp[i-1][0]-v[i], dp[i-1][1]+v[i]);
  }
  std::cout << dp[n][0] << std::endl;
}
