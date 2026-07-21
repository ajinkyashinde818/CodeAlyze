#include <bits/stdc++.h>
using namespace std;

int n;
int a[100000];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] < 0) ++cnt;
  }
  
  if (cnt % 2 == 0) {
    long sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += abs(a[i]);
    }
    cout << sum << endl;
  } else {
    long sum = 0;
    int mn = 1.1e9;
    for (int i = 0; i < n; ++i) {
      sum += abs(a[i]);
      mn = min(mn, abs(a[i]));
    }
    cout << sum - 2 * mn << endl;
  }
}
