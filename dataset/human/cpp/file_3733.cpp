#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (1e5) + 5;
int n, a[N];

// claudio van
int main() {
  scanf("%d", &n);
  int mn = INT_MAX;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] < 0) {
      a[i] *= -1;
      cnt++;
    }
    mn = min(mn, a[i]);
  }
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
  }
  if (cnt % 2 == 1) {
    sum -= 2LL * mn;
  }
  printf("%lld\n", sum);
  return 0;
}
