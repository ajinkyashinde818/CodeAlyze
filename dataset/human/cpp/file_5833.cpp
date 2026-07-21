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
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;

int main() {
  ll n, c;
  cin >> n >> c;
  vector<ll> x(n), v(n);
  rep(i, n) {
    cin >> x[i] >> v[i];
  }
  vector<ll> maxv(n + 1), maxrv(n + 1);
  ll sum = 0;
  ll pre = 0;
  rep(i, n) {
    sum += v[i] - (x[i] - pre);
    pre = x[i];
    maxv[i + 1] = max(maxv[i], sum);
  }
  sum = 0;
  pre = 0;
  rep(i, n) {
    ll dist = (c - x[n - 1 - i]) - pre;
    sum += v[n - 1 - i] - dist;
    maxrv[i + 1] = max(sum, maxrv[i]); 
    pre = c - x[n - 1 - i];
  }

  ll ans = 0;
  rep(i, n) {
    ll t = max(maxv[i + 1], maxv[i + 1] + maxrv[n - 1 - i] - x[i]);
    ll rt = max(maxrv[i + 1], maxrv[i + 1] + maxv[n - 1 - i] - (c - x[n - i - 1]));
    
    chmax(ans, max(t, rt));
    // cout << maxrv[i + 1] << endl;
  }
  cout << ans << endl;
}
