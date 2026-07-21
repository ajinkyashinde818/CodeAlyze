#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

#define int long long
typedef pair<long long, long long> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

int N;
long long L;
long long X[100000], V[100000];
long long solve() {
  long long cur = 0, sum = 0;
  vector<P> st;
  st.pb(P(-1, 0));
  rep(i, N) {
    sum += V[i];
    if (sum-X[i] > cur) {
      cur = sum-X[i];
      st.pb(P(i, cur));
    }
  }
  sum = 0;
  long long m = st.back()._2;
  for (int i=N-1; i>=0; i--) {
    sum += V[i];
    assert(lower_bound(all(st), P(i, -1)) != st.begin());
    long long w = sum - 2LL*(L-X[i]) + (--lower_bound(all(st), P(i, -1)))->_2;
    m = max(m, w);
  }
  return m;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N >> L;
  rep(i, N) cin >> X[i] >> V[i];
  long long m = 0;
  m = max(m, solve());
  rep(i, N) X[i] = L-X[i];
  reverse(X, X+N);
  reverse(V, V+N);
  m = max(m, solve());
  cout << m << "\n";
  return 0;
}
