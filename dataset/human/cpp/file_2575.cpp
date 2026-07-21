#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int minus = 0, min_a = pow(2, 30);
  int i;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 0) {
      minus++;
    }
    a[i] = fabs(a[i]);
    min_a = min(min_a, a[i]);
  }
  long long result = 0;
  if (minus % 2 != 0) {
    result -= min_a * 2;
  }
  for (i = 0; i < n; i++) {
    result += a[i];
  }
  cout << result << endl;
  return 0;
}
