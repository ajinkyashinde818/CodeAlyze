#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll M = 1e9+7;
const ll INF = 1e9+7;

ll n, ans = 1;
ll a[30];
string s;

int main() {
  cin >> n >> s;

  for (ll i = 0; i < n; i++) {
    a[s[i]-'a']++;
  }
  
  for (ll i = 0; i < 26; i++) {
    ans *= a[i] + 1;
    ans %= M;
  }
  
  ans--;
  
  cout << ans << endl;
  return 0;
}
