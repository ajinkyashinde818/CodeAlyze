#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<ll> sum(n + 1, 0);
  for(int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + a[i];
  }
  ll ave = sum[n] / 2;
  ll ans = 1001001001001001001;
  for(int i = 1; i < n; i++) {
    ans = min(ans, abs(sum[n] - sum[i] - sum[i]));
  }
  cout << ans << endl;
  return 0;
}
