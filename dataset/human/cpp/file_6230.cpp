#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <list>

#include <cmath>
#include <algorithm>
#include <cassert>
#include <bitset>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;

#define mp make_pair
#define pb push_back

const int maxn = 1e5+1;
int n;
ll C, x[2][maxn], v[2][maxn];
ll sum[3][2][maxn];
int main()
{
  scanf("%d %lld", &n, &C);
  for (int i = 1; i <= n; ++i)
    {
      scanf("%lld %lld", &x[0][i], &v[0][i]);
      x[1][n+1-i] = C-x[0][i];
      v[1][n+1-i] = v[0][i];
    }

  for (int dir = 0; dir < 2; ++dir)
    for (int i = 1; i <= n; ++i)
      v[dir][i] += v[dir][i-1];

  for (int times = 0; times < 2; ++times)
    for (int dir = 0; dir < 2; ++dir)
      for (int i = 1; i <= n; ++i)
	{
	  sum[times][dir][i] = max(sum[times][dir][i-1], v[dir][i]-(times+1)*x[dir][i]);
	}
  ll ans = 0;
  for (int i = 0; i <= n; ++i)
    ans = max(ans, max(sum[0][0][i]+sum[1][1][n-i], sum[0][1][i]+sum[1][0][n-i]));
  printf("%lld\n", ans);
}
