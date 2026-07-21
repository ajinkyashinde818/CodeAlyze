//
//  respect the past, embrace the future
//  flipping signs
//

#include  <algorithm>
#include  <iostream>
#include  <climits>
#include  <cstdlib>
#include  <cstring>
#include  <cmath>
#include  <cstdio>
#include  <unordered_map>
#include  <map>
#include  <set>
#include  <stack>
#include  <string>
#include  <vector>
#include  <queue>

using namespace :: std;

using vpll = vector <pair <long long, long long> >;
using pll = pair <long long, long long>;
using vll = vector <long long>;
using ll = long long;

#define N (long long) (2e6 + 7)
#define M (long long) (1e9 + 7)
#define INF (long long) (2e18)
#define F first
#define S second

inline void fastInputOutput () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
}

inline void ReadWriteFromFile () {
  freopen("../in.txt", "r", stdin);
  freopen("../out.txt", "w", stdout);
}

ll n, ans, a[N], mn = INF, cnt, neg;

int32_t main (int argc, char *argv[]) {
  fastInputOutput();
  // ReadWriteFromFile();
  
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    neg += (a[i] < 0);
    cnt += (!a[i]);
    ans += abs(a[i]);
    mn = min(mn, abs(a[i]));
  }
  if (!cnt && (neg & 1))
    ans -= mn * 2;
  cout << ans;
}
