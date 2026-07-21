#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n - 1; i++) {
    if (a[i] < 0 && a[i + 1] < 0) {
      a[i] *= -1;
      a[i + 1] *= -1;
    }
    if (a[i] < 0 && a[i + 1] >= 0 && abs(a[i]) > a[i + 1]) {
      a[i] *= -1;
      a[i + 1] *= -1;
    }
  }
  cout << accumulate(a.begin(),a .end(), 0LL) << '\n';
  return 0;
}
