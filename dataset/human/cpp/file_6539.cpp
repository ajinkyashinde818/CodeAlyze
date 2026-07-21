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
#include <random>
#include <iomanip>

using namespace std;
using P = pair<long, long>;

typedef long long int ll;

#define EPS (1e-7)
#define INF (1e18)
#define PI (acos(-1))

#define fillInt(xs)        \
  for (int i = 0; i < (xs).size(); i++) \
    scanf("%d", &xs[i]);
#define fillLong(xs)       \
  for (int i = 0; i < (xs).size(); i++) \
    scanf("%ld", &xs[i]);
#define fillDouble(xs)       \
  for (int i = 0; i < (xs).size(); i++) \
    scanf("%lf", &xs[i]);
#define fillString(xs)       \
  for (int i = 0; i < (xs).size(); i++) \
    cin >> xs[i];
#define sortv(xs) sort(xs.begin(), xs.end())
#define sortvinv(xs) sort(xs.begin(), xs.end(), std::greater<long>())
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin()
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin()
#define bs(xs, x) binary_search(xs.begin(), xs.end(), x)
#define index_of(as, x) \
  distance(as.begin(), lower_bound(as.begin(), as.end(), x))
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define concat(xs, ys) (xs).insert((xs).end(), (ys).begin(), (ys).end())

const int mod = 1000000007;
const int MAX_V = 100005;


struct mint {
    ll x;
    mint(ll x=0):x(x%mod){}

    mint& operator+=(const mint a) {
        if((x += a.x) >= mod) x -= mod;
        return *this;
    }

    mint& operator-=(const mint a) {
        if (x < a.x) {
          x += mod;
        }
        x -= a.x;
        return *this;
    }

    mint& operator*=(const mint a) {
        x = (x * a.x) % mod;
        return *this;
    }

    mint& operator/=(const mint a) {
        *this *= a.inv();
        return *this;
    }

    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }

    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }

    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }

    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }

    mint pow(ll n) const {
        mint a(*this);
        mint res = 1;
        while (n > 0) {
            if (n & 1) res *= a;
            a *= a;
            n >>= 1;
        }
        return res;
    }

    mint inv() const {
        return pow(mod - 2);
    }
};

mint dp1[200005];
long dp2[200005];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  long n;
  cin >> n;

  string s;
  cin >> s;

  dp1[0] = 1;
  rep(i, 2*n) {
    if (s[i] == 'W') {
      if (dp2[i] % 2) {
        dp1[i+1] = dp1[i];
        dp2[i+1] = dp2[i] + 1;
      } else {
        dp1[i+1] = dp1[i] * dp2[i];
        dp2[i+1] = dp2[i] - 1;
      }
    } else {
      if (dp2[i] % 2) {
        dp1[i+1] = dp1[i] * dp2[i];
        dp2[i+1] = dp2[i] - 1;
      } else {
        dp1[i+1] = dp1[i];
        dp2[i+1] = dp2[i] + 1;
      }
    }
  }
  if (dp2[2*n] == 0) {
    rep(i, n) {
      dp1[2*n] *= (i+1);
    }
  } else {
    dp1[2*n] = 0;
  }
  cout << dp1[2*n].x << endl;
}
