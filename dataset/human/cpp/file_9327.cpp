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
#include <chrono>
#include <ctime>

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define P pair<int, int>
#define debug(x) cerr << #x << ": " << x << ", "
#define debugln(x) cerr << #x << ": " << x << '\n'

using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin >> n >> m;
  vector<string> a(n);
  vector<string> b(m);

  rep(i, n) {
    cin >> a.at(i);
  }
  rep(i, m) {
    cin >> b.at(i);
  }

  rep(i, n) {
    rep(j, n) {
      if (i+m > n || j+m > n) continue;
      bool flag = true;
      rep(k, m) {
        rep(l, m) {
          if (a.at(i+k).at(j+l) != b.at(k).at(l)) {
            flag = false;
            break;
          }
        }
        if (!flag) {
          break;
        }
      }
      if (flag) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
