#include<iostream>
#include<cmath>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  long a[n];
  long min_abs = 1000000001, abs_a;
  long abs_sum = 0;
  bool is_even = true;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    abs_a = abs(a[i]);
    if (abs_a < min_abs) min_abs = abs_a;
    abs_sum += abs_a;
    if (a[i] < 0) is_even = !is_even;
  }
  if (!is_even) abs_sum -= min_abs * 2;
  cout << abs_sum << endl;
  return 0;
}
