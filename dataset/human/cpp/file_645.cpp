#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <math.h>
#include <map>
#include <time.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define pb push_back
#define rep(i, a, n) for(int i = (a); i < (n); i++)
#define dep(i, a, n) for(int i = (a); i >= (n); i--)
#define mod (ll)(1e9+7)
#define int ll

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

signed main() {
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  int ans = 0;
  rep(i, 0, 3001) {
    rep(j, 0, 3001) {
      if(r * i + g * j > n) continue;
      if((i * r + j * g) == n || (n - (i * r + j * g)) % b == 0) ans++;
    }
  }
  cout << ans << endl;
}
