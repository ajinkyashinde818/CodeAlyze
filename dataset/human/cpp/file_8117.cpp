#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, sum = 0, ans=1000000000000000000LL;
  cin >> n;
  vector<long long> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
    sum += vec[i];
  }
  long long x=0;
  for (int i = 0; i < n-1; i++) {
    x += vec[i];
    ans = min(abs(sum - 2*x), ans);
  }
  cout << ans << '\n';
}
