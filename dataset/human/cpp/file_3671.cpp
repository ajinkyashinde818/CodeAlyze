#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  int negative_count = 0;
  vector<long> a(n, 0);
  long sum = 0;
  long min_abs = LONG_MAX;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 0) {
      long abso = - 1 * a[i];
      negative_count += 1;
      sum += abso;
      if (abso < min_abs) {
        min_abs = abso;
      }
    } else {
      sum += a[i];
      if (a[i] < min_abs) {
        min_abs = a[i];
      }
    }
  }


  if (negative_count % 2 == 0) {
    cout << sum << endl;
  } else {
    cout << sum - 2 * min_abs << endl;
  }

  return 0;
}
