#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[200006] = {0};

long long solve();

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    if(i != 0) a[i] += a[i - 1];
  }
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long ans = 100000000000000000;
  for(int i = 0; i < n - 1; ++i) {
    long long l, r;
    l = a[i];
    r = a[n - 1] - l;
    ans = min(max(l - r, r - l), ans);
  }
  return ans;
}
