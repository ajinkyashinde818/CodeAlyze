#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<ll,int> p;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  ll s = 0;
  rep(i, n) {
    cin >> a[i];
    s += a[i];
  }
  ll ans = LLONG_MAX;
  ll t = 0;
  rep(i, n - 1) {
    s -= a[i];
    t += a[i];
    ans = min(ans, abs(s - t));
  }
  cout << ans << endl;

}
