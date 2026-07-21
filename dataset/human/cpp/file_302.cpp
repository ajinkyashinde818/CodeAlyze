#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  int result = 0;
  for (int br = 0; br <= n; br++) {
    for (int bg = 0; bg <= n; bg++) {
      int rplusg = br * r + bg * g;
      int remain = n - rplusg;
      if (remain >= 0 && remain % b == 0) {
        result++;
      }
    }
  }
  cout << result << endl;
  return 0;
}
