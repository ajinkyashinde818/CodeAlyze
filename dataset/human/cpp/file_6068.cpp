#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

struct sushi_t {
  lint pos;
  int value;
};

lint solve(lint length, const vector<sushi_t> &sushis) {
  const int n = sushis.size();
  lint result = 0;
  vector<pair<lint, lint>> cands;
  lint acc_value = 0;
  for (int i = 0; i < n; ++i) {
    acc_value += sushis[i].value;
    pair<lint, lint> cand{sushis[i].pos, acc_value - sushis[i].pos};
    result = max(result, cand.second);
    if (cands.empty() || cand.second > cands.back().second)
      cands.push_back(cand);
  }
  acc_value = 0;
  int j = cands.size();
  for (int i = n - 1; i >= 0; --i) {
    acc_value += sushis[i].value;
    while (j - 1 >= 0 && cands[j - 1].first >= sushis[i].pos) --j;
    if (j - 1 >= 0) {
      result = max(result, cands[j - 1].second + acc_value -
                               2LL * (length - sushis[i].pos));
    }
  }
  return result;
}

int main() {
  int n;
  lint length;
  scanf("%d %lld", &n, &length);
  vector<sushi_t> sushis(n);
  for (int i = 0; i < n; ++i)
    scanf("%lld %d", &sushis[i].pos, &sushis[i].value);
  lint result = 0;
  result = max(result, solve(length, sushis));
  for (int i = 0; i < n; ++i)
    sushis[i].pos = length - sushis[i].pos;
  reverse(sushis.begin(), sushis.end());
  result = max(result, solve(length, sushis));
  printf("%lld\n", result);
  return 0;
}
