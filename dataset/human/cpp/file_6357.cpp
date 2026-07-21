#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <numeric>
#include <string>
#include <cassert>

using namespace std;
typedef long long ll;
const ll kMod = 1000000007;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  // init
  ll ans = N;
  ll x = 1;  // open
  ll y = 0;  // closed

  for (int i = 1; i < 2 * N; ++i) {
    int cond = S[i] == 'B' ? 1 : 0;
    if (x % 2 == cond) {
      if (x == 0) {
	cout << 0 << endl;
	return 0;
      }
      ans *= x;
      ans %= kMod;
      --x;
      ++y;
    } else {
      if (N - x - y <= 0) {
	cout << 0 << endl;
	return 0;
      }
      ans *= (N - x - y);
      ans %= kMod;
      ++x;
    }
    
  }

  cout << ans << endl;
  
  return 0;
}
