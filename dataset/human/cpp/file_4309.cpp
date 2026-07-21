#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <unordered_map>

using namespace std;

#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)

long long t, n, m, u, v, q, k, s;
const int N = 2e5 + 500;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 57;

long long arr[N];
string str, ss;
long long a[N], b[N];
multiset <int> aa, bb;
map <int, int> M;
vector <int> adj[N];
bool vis[N];
void dfs(int i) {
   if (vis[i]) return;
   vis[i] = true;
   for (int u : adj[i])
   dfs(u);
}
int main() {
   csl;
   cin >> n;
   int x = 0;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      x ^= a[i];
      M[a[i]];
      aa.insert(a[i]);
   }
   a[0] = x;
   M[x];
   aa.insert(x);
   x = 0;
   for (int i = 1; i <= n; ++i) {
      cin >> b[i];
      x ^= b[i];
      M[b[i]];
      bb.insert(b[i]);
   }
   b[0] = x;
   M[x];
   bb.insert(x);
   if (aa != bb) {
      cout << -1 << '\n';
      return 0;
   }
   int h = 0;
   for (auto &u : M) {
      u.second = ++h;
   }
   int e = 0;
   for (int i = 0; i <= n; ++i) {
      a[i] = M[a[i]];
      b[i] = M[b[i]];
      //cout << a[i] << " " << b[i] << endl;
      if (a[i] != b[i]) {
         adj[a[i]].push_back(b[i]);
         adj[b[i]].push_back(a[i]);
         ++e;
      }
   }
   if (e == 0) {
      cout << 0 << '\n';
      return 0;
   }
   int c = 0;
   for (int i = 1; i <= h; ++i) {
      if (vis[i] || adj[i].size() == 0) continue;
      ++c;
      dfs(i);
   }
   int ans = e - c;
   //cout << e << " " << c << endl;
   if (adj[a[0]].size() != 0) {
      ans += 2 * (c - 1);
      if (a[0] == b[0]) ++ans;
   }
   else {
      ans += 2 * c;
   }
   cout << ans << endl;
   return 0;
}
