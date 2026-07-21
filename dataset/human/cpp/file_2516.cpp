#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

template<typename T>
istream& operator >> (istream& is, vector<T>& vs){
  for(T& v: vs) is >> v;
  return is;
}

int main() {
  int N; cin >> N;
  LL vmin = 1e18;
  LL sum = 0;
  int neg_cnt = 0;
  for (int i = 0; i < N; ++i) {
    LL a; cin >> a;
    if (a < 0) {
      ++neg_cnt;
      a = -a;
    }
    vmin = min(vmin, a);
    sum += a;
  }

  if (neg_cnt % 2 == 1) {
    sum -= 2 * vmin;
  }
  cout << sum << endl;
}
