#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
  
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
  
using namespace std;
  
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
  
const int INF=1<<29;
const double EPS=1e-9;
  
const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};


int main() {
  int N;
  ll C;
  cin >> N >> C;
  vector<ll> X(N), V(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> V[i];
  }
  vector<ll> acc(N + 1);
  for (int i = 0; i < N; i++) {
    acc[i + 1] = acc[i] + V[i];
  }

  vector<ll> ccw_ma(N);
  vector<ll> ccw_i(N);
  ll ma = 0, ma_i = -1;
  for(int i = N - 1; i >= 0; i--) {
    if (acc[N] - acc[i] - (C - X[i]) > ma) {
      ma = acc[N] - acc[i] - (C - X[i]);
      ma_i = i;
    }
    ccw_ma[i] = ma;
    ccw_i[i] = ma_i;
  }

  vector<ll> cw_ma(N);
  vector<ll> cw_i(N);
  ma = 0, ma_i = -1;
  for(int i = 0; i < N; i++) {
    if (acc[i + 1] - X[i] > ma) {
      ma = acc[i + 1] - X[i];
      ma_i = i;
    }
    cw_ma[i] = ma;
    cw_i[i] = ma_i;
  }

  ll ans = 0;
  for(int i = 0; i < N; i++) {
    ans = max(ans, acc[i + 1] - X[i]);
  }
  for(int i = N - 1; i >= 0; i--) {
    ans = max(ans, acc[N] - acc[i] - (C - X[i]));
  }

  for (int i = 0; i < N - 1; i++) {
    if (ccw_i[i] == -1) continue;
    ans = max(ans, acc[i + 1] - 2 * X[i] + ccw_ma[i + 1]);
  }

  for (int i = N - 1; i >= 1; i--) {
    if (cw_i[i] == -1) continue;
    ans = max(ans, acc[N] - acc[i] - 2 * (C - X[i]) + cw_ma[i - 1]);
  }

  cout << ans << endl;

  return 0;
}
