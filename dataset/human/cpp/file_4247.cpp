#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define f first
#define s second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ll long long
#define ld double
#define ull unsigned long long
#define PI pair < int, int > 

const int N = 1e6 + 123;
const int M = 123;
const ld Pi = acos(-1);
const ll Inf = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int Sz = 501;
const int MOD = 1e9 + 7;

void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int mult(int a, int b) {
  return 1ll * a * b % mod;
}
int sum(int a, int b) {
  add(a, b);
  return a;
}

int n, a[N], b[N], e, ans;
vector < int > v1, v2, g[N];
int used[N], timer;

void dfs(int v, int p = -1) {
  used[v] = timer;
  e += g[v].size();
  for (auto to : g[v]) {
    if (!used[to]) {
      dfs(to, v);
    }
  }
}
void solve() {
  cin >> n;
  for (int i = 1;i <= n;i++) {
    cin >> a[i];
    v1.pb(a[i]);
    a[0] ^= a[i];
  }
  v1.pb(a[0]);
  for (int i = 1;i <= n;i++) {
    cin >> b[i];
    v2.pb(b[i]);
    b[0] ^= b[i];
  }
  v2.pb(b[0]);
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  for (int i = 0;i <= n;i++) {
    if (v1[i] != v2[i]) {
      cout << "-1\n";
      return;
    }
  }
  v1.resize(unique(v1.begin(), v1.end()) - v1.begin());
  for (int i = 0;i <= n;i++) {
    a[i] = lower_bound(v1.begin(), v1.end(), a[i]) - v1.begin();
    b[i] = lower_bound(v1.begin(), v1.end(), b[i]) - v1.begin();
    if (a[i] != b[i]) {
      g[a[i]].pb(b[i]);
      g[b[i]].pb(a[i]);
    }
  }
  /*for (int i = 0;i <= n;i++) cout << a[i] << " ";
  cout << endl;
  for (int i = 0;i <= n;i++) cout << b[i] << " ";
  cout << endl;
  for (auto i : v1) cout << i << " ";
  cout << endl;*/
  for (auto i = 0;i <= n;i++) {
    if (g[i].empty()) continue;
    if (used[i] == 0) {
      e = 0;
      timer++;
      dfs(i);
      e >>= 1;
    //  cout << "i = " << i << " e = " << e << " timer = " << timer << " used = " << used[a[0]] << endl;
     // for (auto j : v2) cout << j << " used = " << used[j] << "\n";
      if (used[a[0]] == timer) {
        if (a[0] == b[0]) ans += e;
        else ans += e - 1;
      } else {
        ans += e + 1;
      }
    }
  }
  cout << ans << endl;
}

int main() {
  #ifdef wws
   freopen("in", "r", stdin);
  // freopen("out", "w", stdout);
  #endif 
  ios_base::sync_with_stdio(0);
  int tt = 1; 
  while(tt--) solve();
  return 0;
}
