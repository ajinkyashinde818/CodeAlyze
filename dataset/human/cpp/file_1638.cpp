#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int k = 1; //部分集合の数-1
  bool exist = false;
  while (k <= n) {
    if (n == (k+1)*k/2) {
      exist = true;
      break;
    }
    k++;
  }
  if (!exist) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  if (n == 1) {
    cout << 2 << endl;
    cout << 1 << ' ' << 1 << endl;
    cout << 1 << ' ' << 1 << endl;
    return 0;
  }
  vector<vector<int>> ans(k+1);
  int num = 1, idx1 = 0, idx2 = 1;
  for (int i = k; i; i--) {
    while (idx2 < k+1) {
      ans[idx1].push_back(num);
      ans[idx2].push_back(num);
      idx2++;
      num++;
    }
    idx1++;
    idx2 = idx1+1;
  }
  cout << k+1 << endl;
  rep(i, ans.size()) {
    cout << ans[i].size();
    rep(j, ans[i].size()) {
      cout << ' ' << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}
