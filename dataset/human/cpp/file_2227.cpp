#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int m;
  std::vector<int> v;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &m);
    v.push_back(m);
  }
  std::sort(v.begin(), v.end());
  long long int ans = 0;
  int i;
  for (i = 0; i < n; ++i) {
    if (v[i] < 0) {
      if (i % 2 == 0) {
        if (i + 1 < n) {
          if (v[i + 1] >= 0) {
            if (-v[i] > v[i + 1]) {
              ans += -v[i] - 2 * v[i + 1];
            } else {
              ans += v[i];
            }
          } else {
            ans += -v[i];
          }
        } else {
          ans += v[i];
        }
      } else {
        ans += -v[i];
      }
    } else {
      ans += v[i];
    }
  }

  printf("%lld\n", ans);

  return 0;
}
