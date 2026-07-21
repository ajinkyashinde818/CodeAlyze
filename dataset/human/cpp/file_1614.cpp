#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <map>
#include <utility>
#include <numeric>

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define P pair<int, int>
#define debug(x) cout << #x << ": " << x << ", "
#define debugln(x) cout << #x << ": " << x << '\n'

using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;

  int sum = 0;
  int k = 0;
  for(int i=1; sum <= n; i++) {
    sum += i;
    if (sum == n) {
      k = i;
      break;
    }
  }

  if (k == 0) {
    cout << "No" << endl;
    return 0;
  } else {
    cout << "Yes" << endl;
    cout << k+1 << endl;
  }

  vector<int> vec[k+1];

  int now = 1;
  for(int i=0; i<k; i++) {
    for(int j=i+1; j<k+1; j++) {
      vec[i].push_back(now);
      vec[j].push_back(now);
      now++;
    }
  }

  for(int i=0; i<k+1; i++) {
    cout << k << ' ';
    for(auto e : vec[i]) {
      cout << e << ' ';
    }
    cout << '\n';
  }
}
