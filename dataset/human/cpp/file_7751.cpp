#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main() {
  int n; cin >> n;
  vector<long long> a(n);
  long long sum_all = 0, sum_part = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    sum_all += a[i];
  }

  long long min_ = 100000000000;
  for(int i = 0; i < n - 1; i++) {
    sum_part += a[i];
    long long k = abs(sum_all - 2 * sum_part);
    min_ = min(min_, k);
  }
  cout << min_ << endl;
}
