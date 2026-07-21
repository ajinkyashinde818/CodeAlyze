#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n];
  int mi = 2e9;
  long long ans = 0, neg = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    mi = min(mi, abs(arr[i]));
    ans += abs(arr[i]);
    neg += (arr[i] < 0);
  }
  if (neg & 1) {
    ans -= 2 * mi;
  }
  cout << ans << endl;
  return 0;
}
