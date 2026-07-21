#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  long a[N], s[N], sum = 0, ans = LONG_MAX;
  for (int i=0; i<N; i++) {
    cin >> a[i];
    sum += a[i];
    s[i] = sum;
  }
  for (int i=0; i<N-1; i++) {
    long a = s[i];
    if (abs(sum - 2*a)<ans)
      ans = abs(sum-2*a);
  }
  cout << ans << endl;
  return 0;
}
