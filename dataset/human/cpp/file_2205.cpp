#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <map>
#include <utility>
#include <numeric>
#include <chrono>
#include <ctime>
#include <cassert>
#include <bitset>
#include <iterator>
#include <cmath>
#include <stack>
#include <random>

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define debug(x) cerr << #x << ": " << x << ", "
#define debugln(x) cerr << #x << ": " << x << '\n'

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//constexpr ll mod = 998244353;
constexpr ll mod = 1e9+7;
const double PI = acos(-1.0);
mt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<ll> a(n);
  int negative = 0;
  int zero = 0;
  rep(i, n) {
    cin >> a[i];
    if (a[i]<0) {
      negative++;
    } else if (a[i] == 0) {
      zero++;
    }
  }

  if (zero > 0 || negative%2 == 0) {
    ll ans = 0;
    rep(i, n) {
      ans += abs(a[i]);
    }
    cout << ans << endl;
    return 0;
  }

  ll minabs = INT_MAX;
  ll ans = 0;
  rep(i, n) {
    chmin(minabs, abs(a[i]));
    ans += abs(a[i]);
  }
  ans -= minabs*2;
  cout << ans << endl;
}
