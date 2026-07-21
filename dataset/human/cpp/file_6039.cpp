#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cinttypes>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int N;
  int64_t C;
  cin >> N >> C;
  
  vector<int64_t> X(N);
  vector<int64_t> V(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> V[i];
  }
  
  vector<int64_t> l(N), ml(N);
  l[0] = V[0] - X[0];
  ml[0] = l[0];
  for (int i = 1; i < N; ++i) {
    l[i] = l[i - 1] + V[i] - (X[i] - X[i - 1]);
    ml[i] = max(ml[i - 1], l[i]);
  }
  
  vector<int64_t> r(N), mr(N);
  r[N - 1] = V[N - 1] - (C - X[N - 1]);
  mr[N - 1] = r[N - 1];
  for (int i = N - 2; i >= 0; --i) {
    r[i] = r[i + 1] + V[i] - (X[i + 1] - X[i]);
    mr[i] = max(mr[i + 1], r[i]);
  }
  
  int64_t result = 0;
  result = max(result, ml[N - 1]);
  result = max(result, mr[0]);
  
  for (int i = 0; i < N - 1; ++i) {
    int64_t cand = l[i] + mr[i + 1] - X[i];
    result = max(result, cand);
  }
  for (int i = N - 1; i > 0; --i) {
    int64_t cand = r[i] + ml[i - 1] - (C - X[i]);
    result = max(result, cand);
  }
  
  cout << result << '\n';
    
  return 0;
}
