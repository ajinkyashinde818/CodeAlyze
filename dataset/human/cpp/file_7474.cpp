#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  long long x = 0, y = 0;

  int i;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    y += a[i];
  }

  long long result = LLONG_MAX;

  for (i = 0; i < n - 1; i++) {
    y -= a[i];
    x += a[i];
    result = min(result, (abs(x - y)));
  }

  cout << result << endl;


  return 0;
}
