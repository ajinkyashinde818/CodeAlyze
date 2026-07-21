#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int n, r;
  cin >> n >> r;
  if (10 <= n) {
    cout << r << endl;
  } else {
    cout << r + 100 * (10 - n) << endl;
  }
  return 0;
}
