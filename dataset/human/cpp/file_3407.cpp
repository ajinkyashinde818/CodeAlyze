#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <unordered_set>
#include <unordered_map>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
  int N;
  int minusCnt = 0;
  ll minabs = INT_MAX;
  cin >> N;
  ll total = 0;
  for (int i = 0; i < N; i++) {
    ll A;
    cin >> A;
    if (A < 0) minusCnt++;
    minabs = min(minabs, abs(A));
    total += abs(A);
  }
  if (minusCnt & 1) {
    total -= 2 * minabs;
  }
  cout << total << endl;

  return 0;
}
