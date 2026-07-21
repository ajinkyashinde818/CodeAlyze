#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <climits>

using namespace std;
typedef long long unsigned int ll;
typedef pair<int, int> P;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

// #define amari(x) ((x) % 1000000007)
#define amari(x) ((x) % 998244353)

#define fillInt(xs, x)        \
  for (int i = 0; i < (x); i++) \
    scanf("%d", &xs[i]);
#define fillLong(xs, x)       \
  for (int i = 0; i < (x); i++) \
    scanf("%ld", &xs[i]);
#define fillString(xs, x)       \
  for (int i = 0; i < (x); i++) \
    cin >> xs[i];
#define sortv(xs) sort(xs.begin(), xs.end())
#define sortvdi(xs) sort(xs.begin(), xs.end(), std::greater<int>())
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin()
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin()
#define bs(xs, x) binary_search(xs.begin(), xs.end(), x)

#define rep(i,n) for(long i=0; i<(n); i++)
#define isValidPoint(x, y, mx, my) x >= 0 && x  < mx && y >= 0 && y < my

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

long gcd( long a, long b )
{
    if (a < b) {
      return gcd(b, a);
    } else if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  long r, g, b, n;
  cin >> r >> g >> b >> n;

  long cnt = 0;
  rep(i, n+1) {
    rep(j, n+1) {
      if ((n-i*r-j*g)%b == 0 && (n-i*r-j*g) >= 0) cnt++;
    }
  }
  cout << cnt << endl;
}
