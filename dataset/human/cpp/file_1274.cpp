/**
 *      purpose : 
 *      author  : kyomukyomupurin
 *      created : 
**/

// input/output
#include <iostream>
#include <fstream>
#include <sstream>
// container class
#include <array>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// math, algorithm
#include <algorithm>
#include <cmath>
#include <complex>
#include <numeric>
// etc
#include <bitset>
#include <cctype>
#include <cstring>
#include <chrono>
#include <iomanip>
#include <random>
#include <utility>
// using-directive
using namespace std;
// alias template
using int64 = int64_t;
using pii = pair<int, int>;
using pll = pair<int64_t, int64_t>;
// text macro replacement
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define print(x) cout << (x) << '\n'
#define debug(x) cout << #x << ": " << (x) << '\n'

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, g, b, n; cin >> r >> g >> b >> n;

  int ans = 0;
  for (int i = 0; i < 3001; ++i){
    for (int j = 0; j < 3001; ++j){
      if ((n - (r * i + g * j)) == 0) ++ans;
      else if ((n - (r * i + g * j)) % b == 0 && (n - (r * i + g * j)) >= 0) {++ans;}     
    }
  }

  print(ans);

  return 0;
}
