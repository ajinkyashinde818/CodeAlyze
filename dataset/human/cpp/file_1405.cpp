#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <complex>
#include <valarray>
#include <fstream>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <numeric>

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = Y-1;(X) >= 0;--(X))
#define repa(X,A,Y) for (int (X) = A;(X) <= (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define mod(n, m) (((n)%(m)+(m))%m)
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
const int INFINT = 1 << 30;                          // 1.07x10^ 9
const ll INFLL = 1LL << 60;                          // 1.15x10^18
const double EPS = 1e-10;
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

ll N;

int main() {

  cin >> N;
  ll n = 0, k = 1;
  while (true) {
    if (n == N) break;
    if (n > N) {
      cout << "No" << endl;
      return 0;
    }
    n += k;
    ++k;
  }

  vector<vector<int> > S(k);
  int count = k;
  for (int j = 1; j <= k-1; ++j)  S[0].push_back(j);
  for (int i = 1; i < k; ++i) {
    for (int j = 0; j < k-1; ++j) {
      if (i > j) {
        S[i].push_back(S[j][i-1]);
      } else {
        S[i].push_back(count++);
      }
    }
  }

  cout << "Yes" << endl;
  cout << k << endl;
  rep(i, k) {
    cout << k-1 << ' ';
    rep(j, k-1) printf("%d%c", S[i][j], j+1 == k-1 ? '\n' : ' ');
  }

  return 0;
}
