#include <bits/stdc++.h>
//#include <NTL/ZZ.h>
using namespace std;
//using namespace NTL;
typedef long long ll;
const int inf = 2147483647;

const int maxn = 1e5 + 7;
long long x[maxn], v[maxn];

int main() {
  int n;
  long long c;
  scanf("%d%lld", &n, &c);
  for (int i = 1; i <= n; i++) scanf("%lld%lld", &x[i], &v[i]);
  n++;
  x[n] = c;
  v[n] = 0;
  
  long long tot = 0;
  for (int i = 1; i <= n; i++) tot += v[i];
  for (int i = 1; i <= n; i++) v[i] += v[i - 1];
  //for (int i = 1; i <= n; i++) x[i] += x[i - 1];

  long long ans = max(tot - (c - x[1]), tot - x[n]);
  for (int i = 1; i <= n; i++) ans = max(ans, v[i] - x[i]);
  for (int i = 1; i <= n; i++) ans = max(ans, (tot - v[i - 1]) - (c - x[i]));

  
  long long cur = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, tot - v[i - 1] - c + x[i] + cur);
    cur = max(cur, v[i] - x[i] - x[i]);
    //cout << ans << ' ' << cur << endl;
  }

  cur = 2 * x[n] - v[n];
  for (int i = n; i >= 1; i--) {
    ans = max(ans, tot - c - c + v[i] - x[i] + cur);
    cur = max(cur, -v[i - 1] + x[i] + x[i]);
    //cout << ans << ' ' << tot - c - c + v[i] - x[i] << ' ' << cur << ' ' << -v[i] + x[i] + x[i] << endl;
  }

  cout << max(ans, 0LL) << endl;
  return 0;
}
